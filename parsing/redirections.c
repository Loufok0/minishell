/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                      :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:00:31 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/07 16:32:34 by l              ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**two(char **split, int *code, int i)
{
	free(split[i]);
	split[i] = ft_strdup("<");
	if (!split[i])
		return (ft_free_arr(split, arr_size(split)), NULL);
	i++;
	if (!split[i] || (split[i] && is_problem_char(split[i], code) == 1))
	{
		if (!split[i])
		{
			*code = 2;
			printf("Syntax error near unexpected token `newline'\n");
		}
		ft_free_arr(split, arr_size(split));
		return (NULL);
	}
	i = skip_ispaces(split, ++i);
	limiter(split[i]);
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
				printf("Syntax error near unexpected token `<'\n");
			else if (ft_strnstr(split[i], ">>>", 4))
				printf("Syntax error near unexpected token `>'\n");
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
