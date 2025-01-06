/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:51:17 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/06 19:09:13 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_t_token(t_token *head)
{
	t_token	*temp;

	temp = head;
	while (temp->next)
	{
		if (temp->str)
			free(temp->str);
		if (temp->path)
			free(temp->path);
		temp = temp->next;
		if (temp->prev)
			free(temp);
	}
	if (head)
		free(head);
}
