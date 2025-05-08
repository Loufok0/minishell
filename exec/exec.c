/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:01:18 by ylabussi          #+#    #+#             */
/*   Updated: 2025/05/08 16:19:57 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exe_file(char *path, t_parsed *cmd, char **envp)
{
	int	status;

	status = path_check(path, 'x', cmd->split[0]);
	if (status)
		return (status);
	execve(path, cmd->split, envp);
	return (EXIT_SYSERROR);
}

int	exe_cmd(t_parsed *cmd, int *status, char ***envp)
{
	char	*path;

	if (cmd->next)
		close(cmd->next->fds[0]);
	dup2(cmd->fds[0], 0);
	dup2(cmd->fds[1], 1);
	path = find_exe(cmd->split[0], *envp);
	if (is_builtin(cmd->split[0]))
		*status = exe_builtin(cmd->split, envp, *status, cmd->fds[1]);
	else if (path)
		*status = exe_file(path, cmd, *envp);
	else
	{
		*status = EXIT_NOT_FOUND;
		ft_putstr_fd(cmd->split[0], STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
	}
	exit (*status);
}

int	exe_pipeline_chain(t_parsed *cmd, int *status, char ***envp)
{
	pid_t	cpid;

	if (open_pipe(cmd))
		return (1);
	if (cmd->next)
		cpid = fork();
	else
		cpid = 0;
	if (cpid < 0)
		return (1);
	else if (cpid == 0 && cmd->next)
	{
		close(cmd->fds[1]);
		exe_pipeline_chain(cmd->next, status, envp);
	}
	else
	{
		*status = exe_cmd(cmd, status, envp);
		waitpid(cpid, status, 0);
		exit(*status);
	}
	return (0);
}

void	start_pipeline(t_parsed *cmd, char ***envp, int *status)
{
	pid_t		cpid;

	cpid = fork();
	if (cpid < 0)
		return ;
	else if (cpid == 0)
		exe_pipeline_chain(cmd, status, envp);
	else
		waitpid(cpid, status, 0);
}

void	exe_pipeline(t_parsed *cmd, char ***envp, int *status)
{
	t_parsed	*last;

	last = getlast(cmd);
	if (cmd->infile)
		cmd->fds[0] = open(cmd->infile, O_RDONLY);
	if (last->outfile)
		last->fds[1] = open(last->outfile, last->out_mode | O_WRONLY, 0666);
	if (!cmd->next && is_builtin(cmd->split[0]))
		*status = exe_builtin(cmd->split, envp, *status, cmd->fds[1]);
	else
		start_pipeline(cmd, envp, status);
	if (!*envp)
		return ;
	if (*status > 0xFF)
		*status >>= 8;
}
