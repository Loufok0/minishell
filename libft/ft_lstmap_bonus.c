/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:56:21 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/05 15:55:38 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*next;

	new = NULL;
	while (lst)
	{
		next = ft_lstnew(f(lst->content));
		if (!next)
		{
			ft_lstclear(&next, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new, next);
		lst = lst->next;
	}
	return (new);
}
