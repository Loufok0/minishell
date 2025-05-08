/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:15:25 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/08 18:04:36 by ylabussi         ###   ########.fr       */
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
	
	char	*buffer;
	char	c;
	int		bytes;
	int		i;

	i = 0;
	buffer = (char *)malloc(sizeof(char) * 50);
	if (!buffer)
		return (-1);
	bytes = read(0, &c, 1);
	while (bytes && c != '\n' && g_sig == 0)
	{
		if (c != '\n')
			buffer[i] = c;
		i++;
		bytes = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	return (bytes);
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
