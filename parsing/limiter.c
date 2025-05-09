/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter.c                                           :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:15:25 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/09 15:33:13 by l              ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_line(char **line)
{
	rl_getc_function = getc;
	*line = readline("> ");
	*line = ft_strjoin_f(*line, "\n");
	rl_getc_function = rl_getc;
	return (*line != NULL);
}

int	limiter(char *limiter)
{
	int		fd;
	char	*line;

	limiter = trimm(limiter);
	if (!limiter)
		return (0);
	limiter = ft_strjoin_f(limiter, "\n");
	if (!limiter)
		return (0);
	fd = open(TMP_FILE \
		, O_CREAT | O_TRUNC | O_APPEND | O_WRONLY, 0777);
	if (fd < 0)
		return (printf("Error opening files of LIMITER\n"), 0);
	while (get_line(&line) && g_sig == 0)
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter) + 1) == 0)
			return (free(line), free(limiter), close(fd), 1);
		write(fd, line, ft_strlen(line));
		free(line);
	}
	free(limiter);
	close(fd);
	return (1);
}
