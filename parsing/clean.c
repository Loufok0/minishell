/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:33:16 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/10 18:11:31 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	clean_node(t_parsed *parsed)
{
	int	i;

	i = 0;
	if (!parsed)
		return ;
	while (parsed->split && parsed->split[i])
		free(parsed->split[i++]);
	free(parsed->split[i]);
	if (parsed->infile)
		free(parsed->infile);
	if (parsed->outfile)
		free(parsed->outfile);
	if (parsed->fds[0] != 0)
		close(parsed->fds[0]);
	if (parsed->fds[1] != 1)
		close(parsed->fds[1]);
	if (parsed)
		free(parsed);
}

void	free_chain(t_parsed *head)
{
	t_parsed	*temp;
	char		**t;

	t = head->split;
	while (head)
	{
		temp = head;
		head = head->next;
		clean_node(temp);
	}
	if (t)
		free(t);
}
