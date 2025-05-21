/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:12:59 by ylabussi          #+#    #+#             */
/*   Updated: 2025/05/21 18:36:51 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	sort_envp(char **envp)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i + j + 1])
		{
			if (ft_strncmp(envp[j], envp[j + 1], ft_strlen(envp[j])) > 0)
			{
				tmp = envp[j];
				envp[j] = envp[j + 1];
				envp[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	export_noargs(char **envp, int fdout)
{
	size_t	i;
	size_t	l;

	i = 0;
	sort_envp(envp);
	while (envp[i])
	{
		l = idlen(envp[i]) + 1;
		ft_putstr_fd("declare -x ", fdout);
		write(fdout, envp[i], l);
		if (envp[i][l - 1])
		{
			ft_putchar_fd('"', fdout);
			ft_putstr_fd(envp[i] + l, fdout);
			ft_putchar_fd('"', fdout);
		}
		ft_putchar_fd('\n', fdout);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_export(char **args, char ***envp, int fdout)
{
	size_t	l;
	size_t	i;

	i = 0;
	l = arrlen((void **) args);
	if (l < 2)
		return (export_noargs(*envp, fdout));
	while (++i < l)
	{
		if (args[i][0] == '=')
		{
			ft_putstr_fd("export: `", STDERR_FILENO);
			ft_putstr_fd(args[i], STDERR_FILENO);
			ft_putendl_fd("' is not a valid identifier", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		else if (setvar(args[i], envp))
			return (EXIT_SYSERROR);
	}
	return (EXIT_SUCCESS);
}
