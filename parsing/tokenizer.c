/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:06:44 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/06 17:45:04 by malapoug         ###   ########.fr       */
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

char	*get_echo(char **split, int i)
{
	char	*echo;

	echo = NULL;

	while (split[++i])
	{
		if (split[i][0] && split[i][0] == '"')
			split[i] = ft_strtrim(split[i], "\"");//gerer pour laisser les \"
		echo = ft_strjoin_f(echo, split[i]);
		if (!echo)
			return (NULL);
	}
	return (echo);


}

char	**tokenize(char *rl)
{
	char	**split;
	int		i;

	i = -1;
	split = full_split(rl);
	if (!split)
		return (NULL);
	if (total_occ(split, '"') % 2 != 0 || total_occ(split, '\'') % 2 != 0)//while
		ft_putstr_fd(RED "GERER GNL POUR FINIR \" ET \' (reste a implementer)" RESET, 2);//mettre le /GNL ici
		//rl = ft_strjoin_f(rl, nl);//check
		//free(nl);
	while (split[++i])
	{
		if (ft_strchr(split[i], '"') == 0 && ft_strchr(split[i], '\'') == 0)
			split = list_insert(split, ft_split_let(split[i], ' '), i);//checki
	}
	if (!check_quotes(split, '"'))
		return (ft_free_arr(split, arr_size(split)), NULL);
	if (!check_quotes(split, '\''))
		return (ft_free_arr(split, arr_size(split)), NULL);
	i = -1;
	while (split[++i])
	{
		if (ft_strncmp(split[i], " ", 2) == 0)
		{
			duck_fishing(split, i);//check ?
			i--;
		}
	}
	if (split && split[0] && ft_strncmp(split[0], "echo", 5) == 0)
		ft_putstr_fd(get_echo(split, 0), 1);
	return (split);
}
// ^^^^^ checker partout ^^^^^


/*
 * J'avais pense on [eut faire une boucle while qui parcourt split et split en char *** si le path env
 * de la commande existe et sinon tu le rajoute a la derniere commande comme ce sera un argument
 * et on execute la commande quand on tombe sur le prochain path qui marche ou sur la fin du char **
 *
 *
 * FAIR ATTENTION AU COMPORTEMENT DES ';' la on gere "cat file1 cat file2" alors aue ca ne devrait pas marcher,
 * 					on doit gerer "cat file1; cat file2"
*/
