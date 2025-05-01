#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int main(int, char const **, char **envp)
{
	__pid_t	cpid;
	int		fds1[2];
	int		fds2[2];
	char	*cat[] = {"cat", NULL};
	char	*ls[] = {"ls", NULL};

	pipe(fds1);
	cpid = fork();
	if (cpid < 0)
		return (1);
	else if (cpid == 0)
	{
		close(fds1[1]);
		dup2(fds2[0], 0);
		execve("/usr/bin/ls", ls, envp);
	}
	else
	{
		pipe(fds2);
		cpid = fork();
		if (cpid < 0)
			return (1);
		else if (cpid == 0)
		{
			close(fds1[0]);
			close(fds2[1]);
			dup2(fds2[0], 0);
			dup2(fds1[1], 1);
			execve("/usr/bin/cat", cat, envp);
		}
		else
		{
			close(fds1[0]);
			close(fds1[1]);
			close(fds2[0]);
			dup2(fds2[1], 1);
			execve("/usr/bin/cat", cat, envp);
		}
	}
	return 0;
}

int	exe_pipeline_n(t_parsed *cmd, int *status, char ***envp)
{
	pid_t	cpid;
	char	*path;

	if (open_pipe(cmd))
		return (1);
	cpid = fork();
	if (cpid < 0)
		return (1);
	else if (cpid == 0)
		exe_pipeline_n(cmd->next, status, envp);
	else
	{
		path = find_exe(cmd->split[0], *envp);
		if (is_builtin(cmd->split[0]))
			*status = exe_builtin(cmd->split, envp, *status);
		else if (path)
			*status = exe_file(path, cmd, *envp);
		exit (*status);
	}
}

/*

	fork()
	child:
		rest of the owl
	parent:
		current cmd

*/