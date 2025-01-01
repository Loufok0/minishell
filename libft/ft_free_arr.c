/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:42:07 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/01 15:45:22 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	arr_size_i(int **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_free_arr(char **arr, int i)
{
	while (i > 0)
		free(arr[i--]);
	free(arr[i]);
	free(arr);
}

void	ft_free_arr_i(int **arr, int i)
{
	while (i > 0 && arr)
		free(arr[i--]);
	free(arr[i]);
	if (arr)
		free(arr);
}
