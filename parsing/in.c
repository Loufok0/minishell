/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:53:15 by malapoug          #+#    #+#             */
/*   Updated: 2025/04/25 17:54:19 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**in_one(t_parsed *node, char **split, int *code, int i)
{
	duck_fishing(split, i);
	if (!split[i] || (split[i] && is_problem_char(split[i]) == 1))
	{
		if (!split[i])
		{
			*code = 2;
			printf("Syntax error near unexpected token `newline'\n");
		}
		return (free_chain(node), NULL);
	}
	node->infile = ft_strdup(split[i]);
	if (!node->infile)
		return (free_chain(node), NULL);
	duck_fishing(split, i);
	return (split);
}

char	**in_two(t_parsed *node, char **split, int *code, int i)
{
	duck_fishing(split, i);
	if (!split[i] || (split[i] && is_problem_char(split[i]) == 1))
	{
		if (!split[i])
		{
			*code = 2;
			printf("Syntax error near unexpected token `newline'\n");
		}
		return (free_chain(node), NULL);
	}
	limiter(split[i]);
	duck_fishing(split, i);
	return (split);
}
