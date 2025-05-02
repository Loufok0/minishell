/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:47:21 by ylabussi          #+#    #+#             */
/*   Updated: 2025/05/02 15:36:15 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	updateenvp(char *old, char *new, char ***envp)
{
	int	err;

	if (!old || !new)
		return (0);
	err = setvar_join("OLDPWD=", old, envp)
		| setvar_join("PWD=", new, envp);
	return (err);
}

int	ft_cd(char **args, char ***envp)
{
	char	*old;
	char	*new;
	int		status;

	old = getcwd(NULL, 0);
	if (!old)
		status = EXIT_SYSERROR;
	if (!args[1])
		chdir(getvar("HOME", *envp));
	else if (args[1][0] == '~')
	{
		chdir(getvar("HOME", *envp));
		chdir(args[1] + (args[1][1] != '\0') + 1);
	}
		chdir(args[1]);
	new = getcwd(NULL, 0);
	status = updateenvp(old, new, envp);
	if (old)
		free(old);
	if (new)
		free(new);
	return (status);
}
