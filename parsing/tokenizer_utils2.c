/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:38:22 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/01 19:36:07 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	duck_fishing(char **split, int i)
{
	if (split[i] == NULL && split[i - 1])
		return ;
	free(split[i]);
	while (split[i + 1])
	{
		split[i] = split[i + 1];
		i++;
	}
	split[i] = NULL;
	free(split[i + 1]);
}

int	count_occ(char *str, int c)
{
	int		i;
	int		count;

	if (str == NULL)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	total_occ(char **split, int c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (split[i])
	{
		count += count_occ(split[i], c);
		i++;
	}
	return (count);
}

t_parsed	*join_word(t_parsed *parsed)
{
	t_parsed	*temp;
	int			i;

	temp = parsed;
	while (temp)
	{
		i = 0;
		while (temp->split[i])
		{
			if (temp->split[i] && temp->split[i + 1] && ft_strnstr(temp->split[i], " ", 2) == 0 \
				&& ft_strnstr(temp->split[i + 1], " ", 2) == 0)
			{
				temp->split[i] = ft_strjoin_f(temp->split[i], temp->split[i + 1]);
				if (!temp->split[i])
					return (free_chain(parsed), NULL);
				duck_fishing(temp->split, i + 1);
			}
			else
				i++;
		}
		remove_spaces(temp->split);
		temp = temp->next;
	}
	return (parsed);
}
