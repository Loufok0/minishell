/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:59:18 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/03 15:41:56 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrs;
	unsigned char	*ptrd;
	size_t			i;

	if ((dest == NULL && src == NULL) || n == 0)
		return (dest);
	i = 0;
	ptrs = (unsigned char *)src;
	ptrd = (unsigned char *)dest;
	if (ptrs < ptrd)
	{
		i = n;
		while (i > 0)
		{
			i--;
			ptrd[i] = ptrs[i];
		}
		return (dest);
	}
	while (i < n)
	{
		ptrd[i] = ptrs[i];
		i++;
	}
	return (dest);
}
