/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in.c                                                :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:53:15 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/07 16:32:04 by l              ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**in_one(t_parsed *node, char **split, int *code, int i)
{
	duck_fishing(split, i);
	if (!split[i] || (split[i] && is_problem_char(split[i], code) == 1))
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
	duck_fishing(split, i--);
	return (split);
}

char	**in_two(t_parsed *node, char **split, int *code, int i)
{
	duck_fishing(split, i);
	if (!split[i] || (split[i] && is_problem_char(split[i], code) == 1))
	{
		if (!split[i])
		{
			*code = 2;
			printf("Syntax error near unexpected token `newline'\n");
		}
		return (free_chain(node), NULL);
	}
	duck_fishing(split, i--);
	return (split);
}
