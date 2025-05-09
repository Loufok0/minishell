/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                              :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:24:35 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/09 15:32:06 by l              ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_sig;

void	print_prefix(char *prefix, char *str, char *suffix, int fd)
{
	if (prefix)
		ft_putstr_fd(prefix, fd);
	if (str)
		ft_putstr_fd(str, fd);
	if (suffix)
		ft_putstr_fd(suffix, fd);
}

void	sa(int sig)
{
	g_sig = sig;
	if (sig == SIGQUIT)
		ft_putendl_fd("Quit (core dumped)", STDERR_FILENO);
	else if (sig == SIGINT)
	{
		ft_putchar_fd('\n', STDERR_FILENO);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	main_loop(int *status, char ***envp)
{
	char		*rl;
	t_parsed	*line;

	rl = readline(PROMPT);
	g_sig = 0;
	if (ft_strlen(rl) == 0)
		return (free(rl), rl == NULL);
	add_history(rl);
	line = parse(*envp, rl, status);
	if (!line && *status != 1 && *status != 2)
		return (free(rl), 1);
	else if (line && line->split[0])
	{
		signal(SIGQUIT, sa);
		exe_pipeline(line, envp, status);
		signal(SIGQUIT, SIG_IGN);
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
	signal(SIGQUIT, SIG_IGN);
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
