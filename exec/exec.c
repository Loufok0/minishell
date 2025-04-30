/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:01:18 by ylabussi          #+#    #+#             */
/*   Updated: 2025/04/30 17:39:36 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exe_file(char *path, t_parsed *cmd, char **envp)
{
	struct stat	sb;

	if (!path || access(path, F_OK))
		return (EXIT_NOT_FOUND);
	if (access(path, X_OK))
		return (EXIT_PERMISSION);
	if (lstat(path, &sb) || !S_ISREG(sb.st_mode))
		return (EXIT_PERMISSION + 0x80);
	ft_putendl_fd(path, STDERR_FILENO);
	execve(path, cmd->split, envp);
	return (EXIT_SYSERROR);
}

int	exe_cmd_fork(t_parsed *cmd, char ***envp, int *status)
{
	char	*path;

	if (open_pipe(cmd))
	{
		*status = EXIT_SYSERROR;
		ft_putendl_fd("Could not open pipe\n", STDERR_FILENO);
		return (1);
	}
	path = find_exe(cmd->split[0], *envp);
	if (!path && !is_builtin(cmd->split[0]))
	{
		*status = EXIT_NOT_FOUND;
		return (1);
	}
	cmd->pid = fork();
	if (cmd->pid < 0)
		*status = EXIT_SYSERROR;
	else if (cmd->pid == 0)
		child_process(cmd, status, path, envp);
	if (path)
		free(path);
	if (cmd->fds[1] != 1)
		close(cmd->fds[1]);
	return (0);
}

int	exe_cmd(t_parsed *cmd, char ***envp, int *status)
{
	if (!cmd->split[0])
		return (-1);
	if (!is_builtin(cmd->split[0]))
		return (exe_cmd_fork(cmd, envp, status));
	else
		*status = exe_builtin(cmd->split, envp, *status);
	return (0);
}

int	exe_pipeline_chain(t_parsed *cmd, char ***envp, int *status)
{
	if (exe_cmd_fork(cmd, envp, status))
		return (1);
	if (cmd->next)
		exe_pipeline_chain(cmd->next, envp, status);
	return (0);
}

void	exe_pipeline(t_parsed *cmd, char ***envp, int *status)
{
	t_parsed	*last;

	last = getlast(cmd);
	if (cmd->infile)
		cmd->fds[0] = open(cmd->infile, O_RDONLY);
	if (last->outfile)
		last->fds[1] = open(last->outfile, last->out_mode
				| O_WRONLY | O_CREAT, 0666);
	if (!cmd->next)
		exe_cmd(cmd, envp, status);
	else
		exe_pipeline_chain(cmd, envp, status);
	if (!*envp)
		return ;
	wait_pipeline(cmd, status);
	if (*status > 0xFF)
		*status >>= 8;
	if (*status >= 125)
		print_error_msg(cmd->split[0], *status);
	*status &= 0x7F;
}
