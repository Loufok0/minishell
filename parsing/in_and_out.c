/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_and_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:15:05 by malapoug          #+#    #+#             */
/*   Updated: 2025/04/17 14:28:20 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**in(t_parsed *node, char **split, int *code)
{
	int		i;

	i = -1;
	while (split[++i])
	{
		if (ft_strnstr(split[i], "<", 2))
		{
			duck_fishing(split, i);
			if (!split[i] || (split[i] && is_problem_char(split[i]) == 1))
			{
				if (!split[i])
				{
					*code  = 2;
					printf("Syntax error near unexpected token `newline'");
				}
				return (free_chain(node), NULL);
			}
			node->infile = ft_strdup(split[i]);
			if (!node->infile)
				return (free_chain(node), NULL);
			duck_fishing(split, i);
		}
		else if (ft_strnstr(split[i], "<<", 3))
		{
			duck_fishing(split, i);
			if (!split[i] || (split[i] && is_problem_char(split[i]) == 1))
			{
				if (!split[i])
				{
					*code  = 2;
					printf("Syntax error near unexpected token `newline'");
				}
				return (free_chain(node), NULL);
			}
			limiter(split[i]);
			duck_fishing(split, i);
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
		if (ft_strnstr(split[i], ">", 2))
		{
			duck_fishing(split, i);
			if (!split[i] || (split[i] && is_problem_char(split[i]) == 1))
			{
				if (!split[i])
				{
					*code  = 2;
					printf("Syntax error near unexpected token `newline'");
				}
				node->outfile = ft_strdup("/dev/null");
				if (!node->outfile)
					return (free_chain(node), NULL);
				node->out_mode = O_WRONLY;
				continue ;
			}
			node->outfile = ft_strdup(split[i]);
			if (!node->outfile)
				return (free_chain(node), NULL);
			node->out_mode = O_WRONLY;
			duck_fishing(split, i--);
		}
		else if (ft_strnstr(split[i], ">>", 3))
		{
			duck_fishing(split, i);
			if (!split[i] || (split[i] && is_problem_char(split[i]) == 1))
			{
				if (!split[i])
				{
					*code  = 2;
					printf("Syntax error near unexpected token `newline'");
				}
				node->outfile = ft_strdup("/dev/null");
				if (!node->outfile)
					return (free_chain(node), NULL);
				node->out_mode = O_APPEND;
				continue ;
			}
			node->outfile = ft_strdup(split[i]);
			if (!node->outfile)
				return (free_chain(node), NULL);
			node->out_mode = O_APPEND;
			duck_fishing(split, i--);
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
		temp->split = out(temp, temp->split, code);
		if (!temp->split)
			return (0);
		temp = temp->next;
	}
	return (1);
}
