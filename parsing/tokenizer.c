/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:06:44 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/21 18:57:35 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**split_insert_arr(char ***split, int c)
{
	int		i;

	i = -1;
	while ((*split)[++i])
	{
		(*split) = list_insert((*split), ft_split_let((*split)[i], c), i);
		if (!split)
			return (NULL);
	}
	return (*split);
}

char	**full_split(char *rl)
{
	char	**split;

	split = ft_split_let(rl, '"');
	if (!split)
		return (NULL);
	split = split_insert_arr(&split, ' ');
	if (!split)
		return (ft_free_arr(split, arr_size(split)), NULL);
	split = split_insert_arr(&split, '\'');
	if (!split)
		return (ft_free_arr(split, arr_size(split)), NULL);
	split = split_insert_arr(&split, '|');
	if (!split)
		return (ft_free_arr(split, arr_size(split)), NULL);
	return (split);
}

char	**tokenize(char *rl)
{
	char	**split;
	int		i;

	i = -1;
	split = full_split(rl);
	if (!split)
		return (NULL);
	if (total_occ(split, '\"') % 2 != 0 || total_occ(split, '\'') % 2 != 0) // gerer " ' " '
		ft_putstr_fd(RED "[ツ] Unclosed quote !" RESET, 2);
	if (!check_closed(split, '"', 2))
		return (0);
	if (!check_closed(split, '\'', 2))
		return (0);
	while (split[++i])
	{
		if (ft_strncmp(split[i], " ", 2) == 0)
		{
			duck_fishing(split, i);//check ?
			i--;
		}
	}
	return (split);
}
// ^^^^^ checker partout ^^^^^


/*
 * FAIR ATTENTION AU COMPORTEMENT DES ';' la on gere "cat file1 cat file2" alors aue ca ne devrait pas marcher,
*/
