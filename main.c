/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:24:35 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/01 15:46:49 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
	char	*rl;
	char	**parsed;
	char	*pr;

	rl = NULL;
	pr = prompt();
	while (!ft_strnstr(rl, "exit", ft_strlen(rl)))// voir comment faire avec exceve pour "exit"
	{
		free(rl);
		rl = readline(pr);
		parsed = parse(rl);//voir qu'est ce aue je dois renvoyer (on peut changer en char *** ou n'importe)
		if (!parsed)
			return (0);
		show_arr(parsed);
		//process(parsed);
		//voir comment stocker l'historique
		ft_free_arr(parsed, arr_size(parsed));
	}
	free(pr);
	free(rl);
	return (0);
}
