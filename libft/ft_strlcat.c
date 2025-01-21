/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:36:48 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/21 18:54:33 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s_d;
	size_t	s_s;

	s_d = ft_strlen(dst);
	s_s = ft_strlen((char *)src);
	if (size <= s_d)
		return (size + s_s);
	i = 0;
	while (s_d + i < size - 1 && src[i])
	{
		dst[s_d + i] = src[i];
		i++;
	}
	dst[s_d + i] = '\0';
	return (s_d + s_s);
}

size_t	ft_strlcat_mod(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s_d;
	size_t	s_s;

	(void)size;
	s_d = ft_strlen(dst);
	s_s = ft_strlen((char *)src);
	i = 0;
	while (src[i])
	{
		dst[s_d + i] = src[i];
		i++;
	}
	dst[s_d + i] = '\0';
	return (s_d + s_s);
}
