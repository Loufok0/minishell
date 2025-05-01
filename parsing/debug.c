/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:43:26 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/01 18:14:19 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	show_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
	{
		printf("(null)\n");
		return ;
	}
	while (arr[i])
	{
		ft_putstr_fd(arr[i], 2);
		ft_putstr_fd("\t[sep]\t", 2);
		i++;
	}
	ft_putstr_fd("\n", 1);
}

void	show_t_parsed(t_parsed *parsed)
{
	t_parsed	*temp;
	int			i;

	temp = parsed;
	i = 0;
	while (temp)
	{
		printf("\nNODE %d :\n\n", i++);
		printf("INFILE:\n%s\n\n", temp->infile);
		printf("OUTFILE:\n%s\n\n", temp->outfile);
		printf("\nOUT_MODE:\n%d\n\n", temp->out_mode);
		printf("\nSTR:");
		printf("\n");
		show_arr(temp->split);
		temp = temp->next;
		printf("\n\n");
	}
}
