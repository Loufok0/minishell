/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:27:53 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/03 17:05:51 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*transvaser(int *buffer, char *ptr, int tot)
{
	int	i;

	i = 0;
	while (i < tot)
	{
		if (buffer[tot - i - 1] == -1)
			ptr[i] = '-';
		else
			ptr[i] = buffer[tot - i - 1] + 48;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	*ft_insert(int n, int c)
{
	char	*ptr;
	int		buffer[13];
	int		tot;

	tot = 0;
	while (n >= 10)
	{
		buffer[tot++] = (n % 10);
		n /= 10;
	}
	buffer[tot++] = n;
	if (c == '-')
		buffer[tot++] = -1;
	ptr = malloc(sizeof(char) * (tot + 1));
	if (!ptr)
		return (0);
	return (transvaser(buffer, ptr, tot));
}

char	*ft_itoa(int n)
{
	char	*ptr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		ptr = ft_insert(-n, '-');
	else
		ptr = ft_insert(n, 'a');
	return (ptr);
}

/*
int main()
{
	printf("%s", ft_itoa(234566));
}

*/
