/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:15:25 by malapoug          #+#    #+#             */
/*   Updated: 2025/03/31 16:10:44 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_line(char **line)
{
	char	*buffer;
	char	c;
	int		bytes;
	int		i;

	i = 0;
	buffer = (char *)malloc(sizeof(char) * 50);
	if (!buffer)
		return (-1);
	bytes = read(0, &c, 1);
	while (bytes && c != '\n')
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
	fd = open("./.this_is_a_temporary_file_for_the_eof"\
		, O_CREAT | O_TRUNC | O_APPEND | O_WRONLY, 0777);
		//verifier que ca marche selon les droits de l'executable
	if (fd < 0)
		return (printf("Error opening files of LIMITER\n"), 0);
	while (get_line(&line))
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

//1 ==> open temp_file
//2 ==> write limiter_content
//3 ==> close temp_file
//4 ==> replace "cat << eof" by "cat temp_file"
//5 ==> add temp_file to struct->file_to_delete
//5 ==> exec / process
//6 ==> unlink (path/temp_file)
