#include <unistd.h>
#include <stdlib.h>

int main(int, char const **, char **envp)
{
	__pid_t	cpid;
	int		fds[2];
	char	*cat[] = {"cat", NULL};
	char	*ls[] = {"ls", NULL};

	pipe(fds);
	cpid = fork();
	if (cpid < 0)
		return (1);
	else if (cpid > 0)
	{
		close(fds[0]);
		dup2(fds[1], 1);
		execve("/usr/bin/cat", cat, envp);
	}
	if (cpid == 0)
	{
		close(fds[1]);
		dup2(fds[0], 0);
		execve("/usr/bin/ls", ls, envp);
	}
	return 0;
}
