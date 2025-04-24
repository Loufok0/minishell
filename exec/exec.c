/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:01:18 by ylabussi          #+#    #+#             */
/*   Updated: 2025/04/24 15:33:29 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exe_file(char *path, t_parsed *cmd, char **envp)
{
	if (!path)
		return (EXIT_SYSERROR);
	if (access(path, X_OK))
		return (EXIT_PERMISSION);
	execve(path, cmd->split, envp);
	return (EXIT_SYSERROR);
}

pid_t	exe_cmd_fork(t_parsed *cmd, char ***envp, int *status)
{
	pid_t	cpid;
	char	*path;

	path = find_exe(cmd->split[0], *envp);
	if (!path && !is_builtin(cmd->split[0]))
		return (-1);
	cpid = fork();
	if (cpid == -1)
		*status = EXIT_SYSERROR;
	else if (cpid == 0)
	{
		dup2(cmd->fds[0], 0);
		dup2(cmd->fds[1], 1);
		if (cmd->next != 0)
			close(cmd->next->fds[0]);
		*status = exe_builtin(cmd->split, envp);
		if (*status == EXIT_NOT_FOUND)
			*status = exe_file(path, cmd, *envp);
		exit(*status);
	}
	if (path)
		free(path);
	if (cmd->fds[1] != 1)
		close(cmd->fds[1]);
	return (cpid);
}

pid_t	exe_cmd(t_parsed *cmd, char ***envp, int *status)
{
	if (!is_builtin(cmd->split[0]))
		return (exe_cmd_fork(cmd, envp, status));
	else
		*status = exe_builtin(cmd->split, envp);
	return (0);
}

pid_t	exe_pipeline_chain(t_parsed *cmd, char ***envp, int *status)
{
	pid_t	cpid;

	if (open_pipe(cmd))
	{
		*status = EXIT_SYSERROR;
		perror("msh");
		return (-1);
	}
	cpid = exe_cmd_fork(cmd, envp, status);
	if (cmd->next)
		cpid = exe_pipeline_chain(cmd->next, envp, status);
	return (cpid);
}

void	exe_pipeline(t_parsed *cmd, char ***envp, int *status)
{
	pid_t		cpid;
	t_parsed	*last;

	last = getlast(cmd);
	if (cmd->infile)
		cmd->fds[0] = open(cmd->infile, O_RDONLY);
	if (last->outfile)
		last->fds[1] = open(last->outfile, last->out_mode | O_CREAT, 0666);
	cpid = -1;
	if (!cmd->next)
		cpid = exe_cmd(cmd, envp, status);
	else
		cpid = exe_pipeline_chain(cmd, envp, status);
	if (cpid < 0)
		perror("msh");
	if (cpid > 0)
		waitpid(cpid, status, WUNTRACED);
}
