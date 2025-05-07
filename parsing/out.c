/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                               :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:53:54 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/07 15:45:26 by l              ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	skip_ispaces(char **split, int i)
{
	if (!split[i])
		return (i);
	while (split[i] && (split[i][0] && split[i][0] == ' ' && split[i][1] && split[i][1] == '\0'))
		i++;
	return i;
}

char	**out_one(t_parsed *node, char **split, int *code, int i)
{
	duck_fishing(split, i);
	i = skip_ispaces(split, ++i);
	if (!split[i] || (split[i] && is_problem_char(split[i], code) == 1))
	{
		if (!split[i])
		{
			*code = 2;
			printf("Syntax error near unexpected token `newline'\n");
		}
		return (free_chain(node), NULL);
	}
	node->outfile = ft_strdup(split[i]);
	if (!node->outfile)
		return (free_chain(node), NULL);
	if (close(open(node->outfile, O_CREAT, 0777)))
		return (free_chain(node), NULL);
	node->out_mode |= O_WRONLY;
	duck_fishing(split, i--);
	return (split);
}

char	**out_two(t_parsed *node, char **split, int *code, int i)
{
	duck_fishing(split, i);
	i = skip_ispaces(split, ++i);
	if (!split[i] || (split[i] && is_problem_char(split[i], code) == 1))
	{
		if (!split[i])
		{
			*code = 2;
			printf("Syntax error near unexpected token `newline'\n");
		}
		return (free_chain(node), NULL);
	}
	node->outfile = ft_strdup(split[i]);
	if (!node->outfile)
		return (free_chain(node), NULL);
	if (close(open(node->outfile, O_CREAT, 0777)))
		return (free_chain(node), NULL);
	node->out_mode |= O_APPEND;
	duck_fishing(split, i--);
	return (split);
}
