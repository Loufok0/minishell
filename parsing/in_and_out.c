/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_and_out.c                                        :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:15:05 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/15 15:52:42 by l              ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**in(t_parsed *node, char **split, int *code)
{
	int		i;

	i = -1;
	while (split[++i])
	{
		if (!ft_strncmp(split[i], "<", 2))
		{
			if (*code || !in_one(node, split, code, i))
				return (split);
		}
	}
	return (split);
}

char	**out(t_parsed *node, char **split, int *code)
{
	int		i;

	i = -1;
	while (split && split[++i])
	{
		if (!ft_strncmp(split[i], ">>", 3))
		{
			if (!out_two(node, split, code, i))
				return (NULL);
			i = 0;
		}
		else if (!ft_strncmp(split[i], ">", 2) && split[i][1] != '>')
		{
			if (!out_one(node, split, code, i))
				return (NULL);
			i = 0;
		}
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
		if (*code)
			return (free_chain(head), 0);
		temp->split = out(temp, temp->split, code);
		if (!temp->split)
			return (0);
		if (*code)
			return (free_chain(head), 0);
		temp = temp->next;
	}
	return (1);
}
