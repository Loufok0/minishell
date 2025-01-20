/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:43:49 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/31 15:13:46 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !(*lst) || !del)
		return ;
	if ((*lst)->next)
		ft_lstclear(&(*lst)->next, (*del));
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
