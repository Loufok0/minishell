/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:38:22 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/02 01:04:35 by malapoug         ###   ########.fr       */
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
	t_parsed	*t;
	int			i;

	t = parsed;
	while (t)
	{
		i = 0;
		while (t->split[i])
		{
			if (t->split[i] && t->split[i + 1] \
				&& ft_strnstr(t->split[i], " ", 2) == 0 \
				&& ft_strnstr(t->split[i + 1], " ", 2) == 0)
			{
				t->split[i] = ft_strjoin_f(t->split[i], t->split[i + 1]);
				if (!t->split[i])
					return (free_chain(parsed), NULL);
				duck_fishing(t->split, i + 1);
			}
			else
				i++;
		}
		remove_spaces(t->split);
		t = t->next;
	}
	return (parsed);
}
