/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_and_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:15:05 by malapoug          #+#    #+#             */
/*   Updated: 2025/04/22 17:57:01 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**in(t_parsed *node, char **split, int *code)
{
	int		i;

	i = -1;
	while (split[++i])
	{
		if (ft_strnstr(split[i], "<", 2) && !in_one(node, split, code, i))
			return (NULL);
		else if (ft_strnstr(split[i], "<<", 3) && !in_two(node, split, code, i))
			return (NULL);
	}
	return (split);
}

char	**out(t_parsed *node, char **split, int *code)
{
	int		i;

	i = -1;
	while (split && split[++i])
	{
		if (ft_strnstr(split[i], ">", 2) && !out_one(node, split, code, i))
			return (NULL);
		else if (ft_strnstr(split[i], ">>", 3) \
				&& !out_two(node, split, code, i))
			return (NULL);
	}
	return (split);
}

int	remove_in_out(t_parsed *head, int *code)
{
	t_parsed	*temp;

	temp = head;
	while (temp)
	{
		temp->split = in(temp, temp->split, code);
		if (!temp->split)
			return (0);
		temp->split = out(temp, temp->split, code);
		if (!temp->split)
			return (0);
		temp = temp->next;
	}
	return (1);
}
