/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:06:44 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/05 14:21:37 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**parse(char *rl)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split_let(rl, '"');
	if (!split)
		return (NULL);
	if (total_occ(split, '"') % 2 != 0 || total_occ(split, '\'') % 2 != 0)
		ft_putstr_fd(RED "GERER GNL POUR FINIR \" ET \' (reste a implementer)" RESET, 2);
	//mettre le /GNL ici
	if (total_occ(split, '"') % 2 != 0)
		return (ft_free_arr(split, arr_size(split)), NULL);// peut etre des leaks, a verifier
	if (!check_quotes(split))
		return (ft_free_arr(split, arr_size(split)), NULL);// peut etre des leaks, a verifier
	while (split[i])
	{
		if (ft_strchr(split[i], '"') == 0) // && '{'
			split = list_insert(split, ft_split(split[i], ' '), i);//check		reverse duck fishing...
		i++;
	}
	//split = ft_split(rl, ' | ');	 pour gerer les ';' ?
	//split = ft_split(rl, ' ; ');	 pour gerer les ';' ?
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
