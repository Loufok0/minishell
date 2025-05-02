/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:53:33 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/02 17:05:06 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
