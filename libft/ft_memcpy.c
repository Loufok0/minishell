/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 00:14:45 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/08 11:44:09 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrs;
	unsigned char	*ptrd;
	size_t			i;

	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	i = 0;
	ptrs = (unsigned char *)src;
	ptrd = (unsigned char *)dest;
	while (i < n)
	{
		ptrd[i] = ptrs[i];
		i++;
	}
	return (dest);
}
