/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:56:36 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/31 16:01:57 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	join(char *dst, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (dst[i] != 0)
		i++;
	while (src[j++] != 0)
		dst[i + j] = src[j];
}
