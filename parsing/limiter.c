/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:15:25 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/17 12:27:14 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_fline(char *line, int fd, int status, char **envp);

int	get_line(char **line)
{
	rl_getc_function = getc;
	*line = readline("> ");
	*line = ft_strjoin_f(*line, "\n");
	rl_getc_function = rl_getc;
	return (*line != NULL);
}

static int	loop(int fd, char **envp, int *status)
{
	char	*line;

	get_line(&line);
	if (line && ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
	{
		free(line);
		return (0);
	}
	if (line)
	{
		print_fline(line, fd, *status, envp);
		free(line);
	}
	return (1);
}

int	limiter(char *limiter, int *status, char **envp)
{
	int		fd;

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
	while (g_sig == 0 && loop(fd, envp, status))
		;
	free(limiter);
	close(fd);
	return (1);
}

void	print_fline(char *line, int fd, int status, char **envp)
{
	size_t	i;
	size_t	l;
	char	*tmp;

	i = 0;
	while (i < (size_t)ft_strlen(line) && line[i])
	{
		if (ft_strchr(line, '$'))
			l = ft_strchr(line, '$') - line;
		else
			l = ft_strlen(line);
		write(fd, line + i, l);
		i += l;
		if (line[i] && idlen(line + i + 1) > 0)
		{
			tmp = getvar(line + i + 1, envp);
			if (tmp)
				ft_putstr_fd(tmp, fd);
		}
		else if (line[i] && line[i + 1] == '?')
			ft_putnbr_fd(status, fd);
		else if (line[i] && line[i + 1] == '$')
			;
		else if (line[i] && line[i + 1])
			ft_putchar_fd('$', fd);
		i++;
	}
}
