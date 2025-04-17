/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:06:44 by malapoug          #+#    #+#             */
/*   Updated: 2025/04/17 13:27:45 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**split_insert_arr(char ***split, int c)
{
	int		i;
	char	**temp;

	i = -1;
	while ((*split)[++i])
	{
		temp = ft_split_let((*split)[i], c);
		if (!temp)
			return (NULL); // free
		(*split) = list_insert((*split), temp, i);
		if (!split)
			return (NULL); // free
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
	split = split_insert_arr(&split, ';');//enlever ?
	if (!split)
		return (ft_free_arr(split, arr_size(split)), NULL);
	split = split_insert_arr(&split, '>');
	if (!split)
		return (ft_free_arr(split, arr_size(split)), NULL);
	split = split_insert_arr(&split, '<');
	if (!split)
		return (ft_free_arr(split, arr_size(split)), NULL);
	return (split);
}

char	**full_join_sign(char **split)
{
	if (!check_closed(split, 2))
		return (NULL);
	if (!check_follow(split, "<"))
		return (NULL);
	if (!check_follow(split, ">"))
		return (NULL);
	if (!check_follow(split, "$"))
		return (NULL);
	return (split);
}

char	**tokenize(char *rl, int *code)
{
	char	**split;
	int		i;

	i = -1;
	split = full_split(rl);
	if (!split)
		return (NULL);
	split = full_join_sign(split);
	if (!split)
		return (NULL);
	while (split[++i])
	{
		if (ft_strncmp(split[i], " ", 2) == 0)
			duck_fishing(split, i--);// check ?
	}
	i = -1;
	while (split[++i])
	{
		if (ft_strncmp(split[i], "|", 2) == 0 && split[i + 1] && ft_strncmp(split[i + 1], "|", 2) == 0)
		{
			*code = 2;
			printf("bash: syntax error near unexpected token `%c'\n", (split[i][0])); // pas le bon fd (c'est grave chef?)
			return (ft_free_arr(split, arr_size(split)),  NULL);
		}
	}
	i = -1;
	while (split[++i])
	{
		if (ft_strncmp(split[i], "$", 2) == 0 && split[i + 1] && ft_strncmp(split[i + 1], "?", 2) == 0)
		{
			split[i] = ft_strjoin_f(split[i], split[i + 1]);
			if (!split[i])
				return (ft_free_arr(split, arr_size(split)),  NULL);
			duck_fishing(split, i + 1);
		}
	}
	return (split);
}

//corriger les espaces vides!!  ==>> parsed->(char	*echo)

// ^^^^^ checker partout ^^^^^
