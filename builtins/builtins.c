/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:49:44 by ylabussi          #+#    #+#             */
/*   Updated: 2025/05/05 17:08:45 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	is_builtin(const char *cmd)
{
	if (ft_strncmp(cmd, "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd, "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(cmd, "env", 4) == 0)
		return (1);
	else if (ft_strncmp(cmd, "export", 7) == 0)
		return (1);
	else if (ft_strncmp(cmd, "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(cmd, "unset", 6) == 0)
		return (1);
	else if (ft_strncmp(cmd, "exit", 5) == 0)
		return (1);
	else
		return (0);
}

int	exe_builtin(char **args, char ***envp, int oldstatus, int fdout)
{
	if (ft_strncmp(args[0], "cd", 3) == 0)
		return (ft_cd(args, envp));
	else if (ft_strncmp(args[0], "echo", 5) == 0)
		return (ft_echo(args, fdout));
	else if (ft_strncmp(args[0], "env", 4) == 0)
		return (ft_env(*envp, fdout));
	else if (ft_strncmp(args[0], "export", 7) == 0)
		return (ft_export(args, envp, fdout));
	else if (ft_strncmp(args[0], "pwd", 4) == 0)
		return (ft_pwd(*envp, fdout));
	else if (ft_strncmp(args[0], "unset", 6) == 0)
		return (ft_unset(args, envp));
	else if (ft_strncmp(args[0], "exit", 5) == 0)
		return (ft_exit(args[1], envp, oldstatus));
	else
		return (EXIT_NOT_FOUND);
}
