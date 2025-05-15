/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in.c                                                :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:53:15 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/15 17:17:02 by l              ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**in_one(t_parsed *node, char **split, int *code, int i)
{
	duck_fishing(split, i);
	i = skip_ispaces(split, i);
	if (!split[i] || (split[i] && is_problem_char(split[i], code) == 1))
	{
		if (!split[i])
		{
			*code = 2;
			ft_putendl_fd(MSG_UNEXPECTED_NL, STDERR_FILENO);
		}
		return (split);
	}
	node->infile = ft_strdup(split[i]);
	if (path_check(split[i], 'f', ""))
	{
		*code = 1;
		return (split);
	}
	if (!node->infile)
		return (free_chain(node), NULL);
	duck_fishing(split, i--);
	return (split);
}
