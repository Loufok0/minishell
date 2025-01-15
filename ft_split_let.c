/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_let.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:47:14 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/02 13:04:31 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static int	count_w(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		else if (i == 0 || s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static char	*ft_malloc_w(char *s, char c, int is_sep)
{
	char	*arr;
	int		i;

	if (is_sep)
	{
		arr = ft_substr(s, 0, 1);
	}
	else
	{
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		arr = ft_substr(s, 0, i);
	}
	if (!arr)
		return (NULL);
	return (arr);
}

char	**ft_split_let(const char *s, char c)
{
	char	**arr;
	int		i;

	arr = (char **)malloc((count_w(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			arr[i++] = ft_malloc_w((char *)s, c, 1);
		if (*s == c)
			s++;
		else
		{
			arr[i++] = ft_malloc_w((char *)s, c, 0);
			while (*s && *s != c)
				s++;
		}
		if (!arr[i - 1])
			return (ft_free_arr(arr, i), NULL);
	}
	arr[i] = NULL;
	return (arr);
}
