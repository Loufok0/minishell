/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:55:38 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/03 17:07:06 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char const *set, int c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char	*ret_null_p(int i)
{
	char	*ptr;

	(void)i;
	ptr = (char *)malloc(1 * sizeof(char));
	if (!ptr)
		return (NULL);
	*ptr = '\0';
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	size;
	char	*ptr;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] && ft_is_in_set(set, s1[start]))
		start++;
	if (s1[start] == '\0')
		return (ret_null_p(1));
	end = ft_strlen((char *)s1) - 1;
	while (end > start && ft_is_in_set(set, s1[end]))
		end--;
	size = end - start + 1;
	ptr = malloc((size + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1 + start, size + 1);
	ptr[size] = '\0';
	return (ptr);
}
