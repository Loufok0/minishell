/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:35:36 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/01 18:46:38 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_follow(char **split, char *c)
{
	int		size;
	int		i;

	size = arr_size(split);
	i = 0;
	while (i < size)
	{
		if (split[i + 1] && (ft_strncmp(split[i], c, 1) == 0 \
			&& ft_strncmp(split[i + 1], c, 1) == 0))
		{
			split[i] = ft_strjoin_f(split[i], split[i + 1]);
			if (!split[i])
				return (0);
			duck_fishing(split, i + 1);
			size = arr_size(split);
		}
		else
			i++;
	}
	return (1);
}

int	closing_quote(char **split, char *str, int i)
{
	split[i] = ft_strjoin_f(split[i], str);
	if (!split[i])
		return (0);
	return (1);
}

int	quote_gnl(char **split, int n)
{
	int		count_s;
	int		count_d;
	int		i;

	i = arr_size(split) - 1;
	if (split && ft_strlen(split[i]) == 0)
		return (1);
	count_s = count_occ(split[i], '\'');
	count_d = count_occ(split[i], '\"');
	if (split && split[i] && (count_d % n != 0 && split[i][0] == '\"' \
		&& split[i][ft_strlen(split[i])] != '\"'))
	{
		if (!closing_quote(split, "\"", i))
			return (0);
	}
	if (split && split[i] && (count_s % n != 0 && split[i][0] == '\'' \
		&& split[i][ft_strlen(split[i])] != '\''))
	{
		if (!closing_quote(split, "'", i))
			return (0);
	}
	return (1);
}

int	is_closed(char **split, int i, int count_s, int count_d)
{
	if (split[i] && split[i + 1] && ((count_s % 2 != 0 \
		&& split[i][0] == '\'' \
		&& split[i][ft_strlen(split[i])] != '\'') \
		|| (count_d % 2 != 0 && split[i][0] == '\"' \
		&& split[i][ft_strlen(split[i])] != '\"')))
		return (0);
	return (1);
}

int	check_closed(char **split, int n)
{
	int		size;
	int		i;
	int		count_s;
	int		count_d;

	size = arr_size(split);
	i = 0;
	while (i <= size)
	{
		count_s = count_occ(split[i], '\'');
		count_d = count_occ(split[i], '\"');
		if (!is_closed(split, i, count_s, count_d))
		{
			split[i] = ft_strjoin_f(split[i], split[i + 1]);
			if (!split[i])
				return (0);
			duck_fishing(split, i + 1);
			size = arr_size(split);
			i = 0;
		}
		else
			i++;
	}
	if (split[0] && !quote_gnl(split, n))
		return (0);
	return (1);
}
