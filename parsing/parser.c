/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:06:44 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/31 14:45:56 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	duck_fishing(char **split, int i)
{
	free(split[i]);
	while (split[i + 1])
	{
		split[i] = split[i + 1];
		i++;
	}
	split[i] = NULL;
	free(split[i + 1]);
}// a verifier

int	check_quotes(char **split)
{
	int		size;
	int		i;
	int		count;

	size = arr_size(split);
	i = 0;
	while (i < size)
	{
		count = 0;
		while (count < ft_strlen(split[i]) && ft_strchr(split[i] + count, '\"'))
			count++; // si count impaire str pas fini donc strjoin de lui et du prochain
		if (count % 2 != 0 && split[i + 1])
		{
			split[i] = ft_strjoin(split[i], split[i + 1]);
			if (!split[i])
				return (0);
			duck_fishing(split, i + 1);
		}
		else
			i++;
	}
	if(count % 2 != 0)
		return (ft_putstr_fd("GERER GNL POUR FINIR LE \"", 2), 0);
	return (1);
}

char **parse(char *rl)
{
	char	**split;

	//mettre le /GNL ici
	split = ft_split(rl, ' ');// gerer le split pour qu'il laisse les espaces !!!
	//split = ft_split(rl, ' | ');     pour gerer les ';' ?
	//split = ft_split(rl, ' ; ');     pour gerer les ';' ?
	//split = ft_split(rl, ' " ');     aussi ?
	if (!split)
		return(NULL);
	if (!check_quotes(split))
		return(ft_free_arr(split, arr_size(split)), NULL);// peut etre des leaks, a verifier
	return(split);
}



/*
 * J'avais pense on [eut faire une boucle while qui parcourt split et split en char *** si le path env
 * de la commande existe et sinon tu le rajoute a la derniere commande comme ce sera un argument
 * et on execute la commande quand on tombe sur le prochain path qui marche ou sur la fin du char **
 *
 *
 * FAIR ATTENTION AU COMPORTEMENT DES ';' la on gere "cat file1 cat file2" alors aue ca ne devrait pas marcher,
 * 					on doit gerer "cat file1; cat file2"
*/
