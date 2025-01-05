/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:24:35 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/05 14:15:51 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*rl;
	char	*pr;
	char	**parsed;
	char	**hist;

	(void)ac;
	(void)av;
	rl = NULL;
	hist = NULL;
	pr = prompt(envp);
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
		show_arr(parsed);
		//process(parsed);
		free(pr);
		pr = prompt(envp);
		ft_free_arr(parsed, arr_size(parsed));
	}
	ft_free_arr(hist, arr_size(hist));
	free(pr);
	free(rl);
	return (0);
}

//on vas reorganiser tkt pas mdr
