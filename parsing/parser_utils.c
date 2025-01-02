/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:35:36 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/02 18:19:33 by malapoug         ###   ########.fr       */
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

int	check_quotes(char **split)
{
	int		size;
	int		i;
	int		count;

	size = arr_size(split);
	i = 0;
	while (i <= size)
	{
		count = count_occ(split[i], '"');
		if ((count % 10) % 2 != 0 && split[i + 1])
		{
			split[i] = ft_strjoin_f(split[i], split[i + 1]);
			if (!split[i])
				return (0);
			duck_fishing(split, i + 1);
			size--;
		}
		else
			i++;
	}
	return (1);
}

char	**list_insert(char **lst1, char **lst2, int n)
{
	char	**new;
	int		size;
	int		i;
	int		j;

	if (!lst1 || !lst2)
		return (NULL);
	if (n >= arr_size(lst1))
		return (NULL);
	size = arr_size(lst1) - 1 + arr_size(lst2);
	new = malloc((size + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < n)
		new[i] = strdup(lst1[i]);
	while (lst2[++j])
		new[i + j] = strdup(lst2[j]);
	while (lst1[n + 1])
		new[j + i++] = strdup(lst1[n++ + 1]);
	new[i + j] = NULL;
	ft_free_arr(lst2, arr_size(lst2));
	return (ft_free_arr(lst1, arr_size(lst1)), new);
}
