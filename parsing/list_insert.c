/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:15:54 by malapoug          #+#    #+#             */
/*   Updated: 2025/04/24 18:37:20 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	boucle_1(char **lst1, char **new, int n, int *i)
{
	while (++(*i) < n)
	{
		new[*i] = ft_strdup(lst1[*i]);
		if (!new[*i])
		{
			new[*i] = NULL;
			ft_free_arr(new, arr_size(new));
			free(new);
			return (0);
		}
	}
	return (1);
}

int	boucle_2(char **lst2, char **new, int i, int *j)
{
	while (lst2[++(*j)])
	{
		new[i + *j] = ft_strdup(lst2[*j]);
		if (!new[i + *j])
		{
			new[i + *j] = NULL;
			ft_free_arr(new, arr_size(new));
			free(new);
			return (0);
		}
	}
	return (1);
}

int	boucle_3(char **lst1, char **new, int *i, int j)
{
	int	save;

	save = *i;
	while (lst1[(*i) - save + 1])
	{
		new[j + (*i)] = ft_strdup(lst1[(*i) - save + 1]);
		if (!new[*i])
		{
			new[*i] = NULL;
			ft_free_arr(new, arr_size(new));
			free(new);
			return (0);
		}
		(*i)++;
	}
	return (1);
}

void	ft_free_double(char **lst1, char **lst2)
{
	ft_free_arr(lst1, arr_size(lst1));
	ft_free_arr(lst2, arr_size(lst2));
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
	if (!boucle_1(lst1, new, n, &i))
		return (ft_free_double(lst1, lst2), NULL);
	if (!boucle_2(lst2, new, i, &j))
		return (ft_free_double(lst1, lst2), NULL);
	if (!boucle_3(lst1 + n, new, &i, j))
		return (ft_free_double(lst1, lst2), NULL);
	new[i + j] = NULL;
	ft_free_double(lst1, lst2);
	return (new);
}
