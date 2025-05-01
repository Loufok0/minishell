/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:53:33 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/01 18:37:20 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	has_prob_char(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '=')
		return (printf("Export: `%c': not a valid identifier", str[0]), 0);
	while (str[i])
	{
		if (str[i] != '=' && ft_strchr(METACHARSET, str[i]))
			return (printf("Export: `%c': not a valid identifier", str[i]), 0);
		i++;
	}
	return (0);
}

int	check_export(t_parsed *parsed)
{
	t_parsed	*temp;
	int			found;
	int			i;

	temp = parsed;
	found = 0;
	while (temp)
	{
		i = 0;
		while (parsed->split[i])
		{
			if (ft_strnstr(temp->split[i], "export", 7) != 0)
			{
				i++;
				found = 1;
			}
			if (found == 1 && has_prob_char(temp->split[i]))
				return (free_chain(parsed), 0);
			i++;
		}
		temp = temp->next;
	}
	return (1);
}

char	**join_export(char **split)
{
	char	*temp;
	int		i;
	int		found;

	i = -1;
	found = 0;
	while (split[++i])
	{
		if (ft_strnstr(split[i], "export", 7) != 0)
			found = 1;
		if (found && (split[i] && split[i][ft_strlen(split[i])] == '=' ) \
			&& (split[i + 1] && (split[i + 1][ft_strlen(split[i + 1])] == '\'' \
			|| split[i + 1][ft_strlen(split[i + 1])] == '\"')))
		{
			temp = ft_strjoin(split[i + 1], split[i + 2]);
			if (!temp)
				return (ft_free_arr(split, arr_size(split)), NULL);
			split[i + 1] = temp;
			duck_fishing(split, i + 2);
		}
	}
	return (split);
}
