/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:12:59 by ylabussi          #+#    #+#             */
/*   Updated: 2025/05/02 16:12:45 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	export_noargs(char **envp, int fdout)
{
	size_t	i;
	size_t	l;

	i = 0;
	while (envp[i])
	{
		l = idlen(envp[i]) + 1;
		ft_putstr_fd("declare -x ",fdout);
		write(fdout, envp[i], l);
		ft_putchar_fd('"',fdout);
		ft_putstr_fd(envp[i] + l,fdout);
		ft_putendl_fd("\"",fdout);
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
		if (!args[i][idlen(args[i])])
			continue ;
		else if (args[i][0] == '=' || args[i][idlen(args[i])] != '=')
		{
			ft_putstr_fd("export: `", STDERR_FILENO);
			ft_putstr_fd(args[i], STDERR_FILENO);
			ft_putendl_fd("' is not a valid identifier", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		if (setvar(args[i], envp))
			return (EXIT_SYSERROR);
	}
	return (EXIT_SUCCESS);
}
