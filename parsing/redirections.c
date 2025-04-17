/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:00:31 by malapoug          #+#    #+#             */
/*   Updated: 2025/04/17 15:16:19 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**triple(char **split, int *code, int i)
{
	int		fd;

	free(split[i]);
	split[i] = ft_strdup("<");
	if (!split[i])
		return (ft_free_arr(split, arr_size(split)), NULL);
	i++;
	if (!split[i] || (split[i] && is_problem_char(split[i]) == 1))
	{
		if (!split[i])
		{
			*code = 2;
			printf("Syntax error near unexpected token `newline'");
		}
		ft_free_arr(split, arr_size(split));
		return (NULL);
	}
	fd = open("./.this_is_a_temporary_file_for_the_eof", O_CREAT | O_TRUNC | O_APPEND | O_WRONLY, 0777);//verifier que ca marche selon les droits de l'executable
	if (fd < 0)
		return (ft_free_arr(split, arr_size(split)), printf("Error opening files of LIMITER\n"), NULL);
	split[i] = trimm(split[i]);
	if (!split[i])
		return (ft_free_arr(split, arr_size(split)), NULL);
	write(fd, split[i], ft_strlen(split[i])); //check
	close(fd);
	free(split[i]);
	split	[i] = ft_strdup(".this_is_a_temporary_file_for_the_eof");
	if (!split[i])
		return (ft_free_arr(split, arr_size(split)), NULL);
	return (split);
}

char	**two(char **split, int *code, int i)
{
	free(split[i]);
	split[i] = ft_strdup("<");
	if (!split[i])
		return (ft_free_arr(split, arr_size(split)), NULL);
	i++;
	if (!split[i] || (split[i] && is_problem_char(split[i]) == 1))
	{
		if (!split[i])
		{
			*code = 2;
			printf("Syntax error near unexpected token `newline'");
		}
		ft_free_arr(split, arr_size(split));
		return (NULL);
		split = list_insert(split, tokenize(split[i], code), i);
		if (!split)
			return (NULL);
	}
	return (split);
}

char	**handle_redirections(char **split, int *code)
{
	int		i;

	i = -1;
	while (split[++i])
	{
		if (ft_strnstr(split[i], "<<<", 4))
		{
			split = triple(split, code, i);
			if (!split)
				return (NULL);
			i = 0;
		}
		else if (ft_strnstr(split[i], "<<", 3))
		{
			split = two(split, code, i);
			if (!split)
				return (NULL);
			i = 0;
		}
	}
	return (split);
}
