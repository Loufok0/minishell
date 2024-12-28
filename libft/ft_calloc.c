/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:02:32 by malapoug          #+#    #+#             */
/*   Updated: 2024/09/28 00:28:52 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*arr;
	int		size;

	size = num_elements * element_size;
	arr = malloc(size);
	if (!arr)
		return (0);
	ft_memset(arr, 0, size);
	return (arr);
}
