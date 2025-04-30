/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:12:46 by ylabussi          #+#    #+#             */
/*   Updated: 2025/04/30 17:39:03 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	print_error_msg(char *str, int status)
{
	ft_putstr_fd(str, STDERR_FILENO);
	if (status == EXIT_NOT_FOUND)
		ft_putendl_fd(": command not found", STDERR_FILENO);
	else if (status == EXIT_PERMISSION)
		ft_putendl_fd(": permission denied", STDERR_FILENO);
	else if (status == EXIT_PERMISSION + 0x80)
		ft_putendl_fd(": is  a directory", STDERR_FILENO);
}

void	child_process(t_parsed *cmd, int *status, char *path, char ***envp)
{
	if (cmd->next)
		close(cmd->next->fds[0]);
	dup2(cmd->fds[0], 0);
	dup2(cmd->fds[1], 1);
	*status = exe_builtin(cmd->split, envp, *status);
	if (*status == EXIT_NOT_FOUND)
		*status = exe_file(path, cmd, *envp);
	exit(*status);
}

void	wait_pipeline(t_parsed *cmd, int *status)
{
	if (!cmd)
		return ;
	if (cmd->pid > 0)
		waitpid(cmd->pid, status, 0);
	wait_pipeline(cmd->next, status);
}
