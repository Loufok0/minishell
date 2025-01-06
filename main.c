/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:24:35 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/06 18:58:15 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*rl;
	char	*pr;
	t_token	*list;

	(void)ac;
	(void)av;
	rl = NULL;
	pr = prompt(envp);
	while (!ft_strnstr(rl, "exit", ft_strlen(rl)))// voir comment faire avec exceve pour "exit"
	{
		free(rl);
		rl = readline(pr);
		list = parse(envp, rl);//voir qu'est ce que je dois renvoyer (on peut changer en char *** ou n'importe)
		if (!list)
			break ;
		//ft_putstr_fd(get_prev_hist(hist, 0), 1);
		//show_arr(hist);
		//process(parsed);
		free(pr);
		pr = prompt(envp);
	}
	free_t_token(list);
	free(pr);
	free(rl);
	return (0);
}

//on vas reorganiser tkt pas mdr
