/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                            :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:17:34 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/21 18:42:53 by l              ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	count_pipes(char **split)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (split[++i])
	{
		if (split[i][0] != '\'' && split[i][0] != '"' \
			&& ft_strnstr(split[i], "|", 2))
			count++;
	}
	return (count);
}

char	**cut_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		if (ft_strnstr(split[i], "|", 2))
		{
			free(split[i]);
			split[i] = NULL;
			return (split + i);
		}
	}
	return (split + i);
}

void	init_node(char **split, t_parsed *node)
{
	node->split = split;
	node->infile = NULL;
	node->outfile = NULL;
	node->out_mode = 0;
	node->fds[0] = 0;
	node->fds[1] = 1;
}

t_parsed	*create_chain(char **split, int n_node)
{
	t_parsed	*head;
	t_parsed	*temp;

	head = malloc(sizeof(t_parsed));
	if (!head)
		return (NULL);
	init_node(split, head);
	temp = head;
	while (n_node > 0)
	{
		temp->next = malloc(sizeof(t_parsed));
		if (!temp->next)
		{
			free_chain(head);
			return (NULL);
		}
		temp = temp->next;
		split = cut_split(split + 1) + 1;
		init_node(split, temp);
		n_node--;
	}
	temp->next = NULL;
	return (head);
}

t_parsed	*struct_maker(char **split, int *code)
{
	t_parsed	*parsed;

	parsed = create_chain(split, count_pipes(split));
	if (!parsed)
		return (*code = 2, ft_putendl_fd("Error while creating struct", \
			STDERR_FILENO), NULL);
	if (!remove_in_out(parsed, code))
		return (NULL);
	return (parsed);
}
