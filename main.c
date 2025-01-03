/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:24:35 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/03 13:46:28 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*rl;
	char	*pr;
	char	**parsed;
	char	**hist;

	rl = NULL;
	hist = NULL;
	pr = prompt();
	while (!ft_strnstr(rl, "exit", ft_strlen(rl)))// voir comment faire avec exceve pour "exit"
	{
		free(rl);
		rl = readline(pr);
		if (!handle_hist(&hist, rl))
			break;
		parsed = parse(rl);//voir qu'est ce que je dois renvoyer (on peut changer en char *** ou n'importe)
		if (!parsed)
			break ;
		//ft_putstr_fd(get_prev_hist(hist, 0), 1);
		//show_arr(hist);
		//show_arr(parsed);
		//process(parsed);
		ft_free_arr(parsed, arr_size(parsed));
	}
	ft_free_arr(hist, arr_size(hist));
	free(pr);
	free(rl);
	return (0);
}

//on vas reorganiser tkt pas mdr
