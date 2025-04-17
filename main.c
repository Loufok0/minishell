/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:24:35 by malapoug          #+#    #+#             */
/*   Updated: 2025/04/17 13:44:34 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*rl;
	char	*pr;
	int		code;
	t_parsed	*list;

	(void)ac;
	(void)av;
	rl = NULL;
	code = 0;
	pr = prompt(envp);
	while (!ft_strnstr(rl, "exit", ft_strlen(rl)))// voir comment faire avec exceve pour "exit"
	{
		if (rl)
			free(rl);
		rl = readline(pr);
		list = parse(envp, rl, &code);
		if (!list && code != 2)
			break ;
		if (code != 2)
		{
			//process(list);
			free_chain(list);
		}
		free(pr);
		pr = prompt(envp);
	}
	free(pr);
	free(rl);
	return (0);
}

//on vas reorganiser tkt pas mdr
