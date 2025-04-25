/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:24:35 by malapoug          #+#    #+#             */
/*   Updated: 2025/04/25 17:26:59 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
int	main(int ac, char **av, char **envp)
{
	char	*rl;
	char	*pr;
	int		code;
	t_parsed	*list;

	(void)ac;
	(void)av;
	envp = ft_arrdup(envp);
	rl = NULL;
	code = 0;
	pr = prompt(envp);
	while (!ft_strnstr(rl, "exit", ft_strlen(rl)))
	// voir comment faire avec exceve pour "exit"
	{
		if (rl)
			free(rl);
		rl = readline(pr);
		list = parse(envp, rl, &code);
		if (!list && code != 2)
			break ;
		if (code != 2)
		{
			//process(list);
			free_chain(list);
		}
		free(pr);
		pr = prompt(envp);
	}
	free(pr);
	free(rl);
	return (0);
}*/

//on vas reorganiser tkt pas mdr

void	sa(int sig)
{
	if (sig == 3)
		ft_putendl_fd("quit (core dumped)", STDERR_FILENO);
	else
		ft_putchar_fd('\n', STDERR_FILENO);
}

int	main_loop(char *pr, int *status, char ***envp)
{
	char		*rl;
	t_parsed	*line;

	rl = readline(pr);
	if (ft_strlen(rl) == 0)
		return (free(rl), free(pr), rl == NULL);
	line = parse(*envp, rl, status);
	if (!line && *status != 2)
		return (free(rl), free(pr), 1);
	else if (*status != 2)
	{
		exe_pipeline(line, envp, status);
		fprintf(stderr, "exit status - %i\n", *status & 0xFF);
		free_chain(line);
	}
	return (free(rl), free(pr), 0);
}

int	main(int argc, char **argv, char **envp)
{
	int		status;
	char	*pr;

	envp = ft_arrdup(envp);
	if (!envp)
		return (1);
	signal(SIGINT, sa);
	signal(SIGQUIT, sa);
	while (envp)
	{
		pr = prompt(envp);
		if (!pr || main_loop(pr, &status, &envp))
			break ;
	}
	return (status);
	argc++;
	argv++;
}
