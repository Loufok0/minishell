/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:53:54 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/01 17:30:54 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**out_one(t_parsed *node, char **split, int *code, int i)
{
	duck_fishing(split, i);
	if (!split[i] || (split[i] && is_problem_char(split[i]) == 1))
	{
		if (!split[i])
		{
			*code = 2;
			printf("Syntax error near unexpected token `newline'\n");
		}
		node->outfile = ft_strdup("/dev/null");
		if (!node->outfile)
			return (free_chain(node), NULL);
		node->out_mode |= O_WRONLY;
		return (split);
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
	if (!split[i] || (split[i] && is_problem_char(split[i]) == 1))
	{
		if (!split[i])
		{
			*code = 2;
			printf("Syntax error near unexpected token `newline'\n");
		}
		node->outfile = ft_strdup("/dev/null");
		if (!node->outfile)
			return (free_chain(node), NULL);
		node->out_mode |= O_APPEND;
		return (split);
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
