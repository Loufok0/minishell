/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:00:31 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/09 03:40:53 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
char	*get_lim(char **split, int i)
{
	while (split[i] && split[i + 1] && ft_strncmp(split[i + 1], " ", 2))
	{
		while (split[i + 1] && !ft_strncmp(split[i + 1], "\"\"", 3))
			duck_fishing(split, i + 1);
		split[i] = ft_strjoin_f(trimm(split[i]), trimm(split[i + 1]));
		if (!split[i])
			return (ft_free_arr(split, arr_size(split)), NULL);
		duck_fishing(split, i + 1);
	}
	return (split[i]);
}
*/
char	**two(char **split, int *code, int i)
{
	free(split[i]);
	split[i] = ft_strdup("<");
	if (!split[i])
		return (ft_free_arr(split, arr_size(split)), NULL);
	i = skip_ispaces(split, ++i);
	if (!split[i] || (split[i] && is_problem_char(split[i], code) == 1))
	{
		if (!split[i])
		{
			*code = 2;
			ft_putendl_fd(MSG_UNEXPECTED_NL, STDERR_FILENO);
		}
		ft_free_arr(split, arr_size(split));
		return (NULL);
	}
	limiter(split[i]);
	if (g_sig)
	{
		*code = 2;
		return (NULL);
	}
	split[i] = ft_strdup(TMP_FILE);
	return (split);
}

char	**handle_redirections(char **split, int *code)
{
	int		i;

	i = -1;
	while (split[++i])
	{
		if (ft_strnstr(split[i], "<<<", 4) \
			|| ft_strnstr(split[i], ">>>", 4))
		{
			if (ft_strnstr(split[i], "<<<", 4))
				ft_putendl_fd(MSG_UNEXPECTED_LEFT_CHEVRON, STDERR_FILENO);
			else if (ft_strnstr(split[i], ">>>", 4))
				ft_putendl_fd(MSG_UNEXPECTED_RIGHT_CHEVRON, STDERR_FILENO);
			*code = 2;
			ft_free_arr(split, arr_size(split));
			return (NULL);
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
