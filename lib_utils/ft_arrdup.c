/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:58:06 by ylabussi          #+#    #+#             */
/*   Updated: 2025/04/24 15:39:35 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_arrdup(char **arr)
{
	size_t	i;
	size_t	alen;
	char	**new;

	i = 0;
	alen = arrlen((void **) arr);
	new = malloc((alen + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	while (i < alen)
	{
		new[i] = ft_strdup(arr[i]);
		if (!new[i])
			break ;
		i++;
	}
	new[alen] = NULL;
	if (i < alen)
	{
		ft_free_arr(new, i);
		return (NULL);
	}
	return (new);
}
