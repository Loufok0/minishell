/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:24:35 by malapoug          #+#    #+#             */
/*   Updated: 2025/04/30 17:37:36 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sa(int sig)
{
	char	*pr;

	pr = "\033[34m\n<$$$> \033[0m";
	if (sig == 3)
		ft_putstr_fd("\t", 1);
	else
		ft_putstr_fd(pr, 1);
	sig++;
}

int	main_loop(int *status, char ***envp)
{
	char		*rl;
	t_parsed	*line;

	rl = readline(PROMPT);
	if (ft_strlen(rl) == 0)
		return (free(rl), rl == NULL);
	add_history(rl);
	line = parse(*envp, rl, status);
	if (!line)
		return (free(rl), 1);
	else if (line->split[0])
	{
		exe_pipeline(line, envp, status);
		fprintf(stderr, "exit status - %i\n", *status);
		free_chain(line);
	}
	return (free(rl), 0);
}

int	main(int argc, char **argv, char **envp)
{
	int		status;

	envp = ft_arrdup(envp);
	if (!envp)
		return (1);
	signal(SIGINT, sa);
	signal(SIGQUIT, sa);
	while (envp)
	{
		if (main_loop(&status, &envp))
			break ;
	}
	rl_clear_history();
	exit (status);
	argc++;
	argv++;
}
