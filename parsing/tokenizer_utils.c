/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:35:36 by malapoug          #+#    #+#             */
/*   Updated: 2025/04/24 15:36:21 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	printf(RED "[ツ] Unclosed quote !\n" RESET);
	printf("We closed it with: %c\n", str[0]);
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
		if (split[i] && split[i + 1] && ((count_s % n != 0 \
			&& split[i][0] == '\'' \
			&& split[i][ft_strlen(split[i])] != '\'') \
			|| (count_d % n != 0 && split[i][0] == '\"' \
			&& split[i][ft_strlen(split[i])] != '\"')))
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
	if (split[0] && !quote_gnl(split, n))
		return (0);
	return (1);
}

char	**list_insert(char **lst1, char **lst2, int n)
{
	char	**new;
	int		size;
	int		i;
	int		j;

	if (!lst1 || !lst2 || n >= arr_size(lst1))
		return (NULL);
	size = arr_size(lst1) - 1 + arr_size(lst2);
	new = malloc((size + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < n)
	{
		new[i] = ft_strdup(lst1[i]);
		free(lst1[i]);
	}
	free(lst1[i]);
	while (lst2[++j])
	{
		new[i + j] = ft_strdup(lst2[j]);
		free(lst2[j]);
	}
	free(lst2[j]);
	free(lst2);
	while (lst1[n + 1])
	{
		new[j + i++] = ft_strdup(lst1[n + 1]);
		free (lst1[n + 1]);
		n++;
	}
	free(lst1[n + 1]);
	free(lst1);
	new[i + j] = NULL;
	return (new);
}
