/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:51:17 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/07 15:32:57 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_t_token(t_token *head)
{
	t_token	*temp;

	while (head->next)
	{
		free(head->str);
		free(head->path);
		temp = head;
		head = head->next;
		free(temp);
	}
//	if (head)
//		free(head);
}
