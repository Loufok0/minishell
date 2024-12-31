/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:24:35 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/31 14:54:18 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
	char *rl;
	char **parsed;

	rl = NULL;
	while (!ft_strnstr(rl, "exit", ft_strlen(rl)))// voir comment faire avec exceve pour "exit"
	{
		rl = readline(prompt());
		parsed = parse(rl);//voir qu'est ce aue je dois renvoyer (on peut changer en char *** ou n'importe)
		if (!parsed)
			return (0);
		show_arr(parsed);
		//process(parsed);
		//voir comment stocker l'historique
		//free parsed!!! et rl ?
	}
	if (rl)
		free(rl);
	ft_free_arr(parsed, arr_size(parsed));
	return (0);
}
