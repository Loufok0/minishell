/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:24:35 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/03 13:44:04 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_prev_hist(char **hist, int ind)
{
	char	*last;
	int		i;

	i = 0;
	if (ind > HIST_SIZE)
		return (NULL);
	last = NULL;
	while (hist[i] && hist[i + 1] && i < HIST_SIZE)
		i++;
	last = hist[i - ind];
	return (last);
}

void	shift_left(char ***arr)
{
	int	i;

	if (!(*arr) || !(*arr)[0])
		return;
	free((*arr)[0]);
	i = 0;
	while ((*arr)[i + 1])
	{
		(*arr)[i] = (*arr)[i + 1];
		i++;
	}
	(*arr)[i] = NULL;
}

int	add_hist(char ***hist, char *rl)
{
	int	i;

	i = 0;
	while ((*hist)[i] && i < HIST_SIZE)
		i++;
	if (i >= HIST_SIZE)
	{
		shift_left(hist);
		(*hist)[HIST_SIZE - 1] = ft_strdup(rl);
		if (!(*hist)[HIST_SIZE - 1])
			return (0);
	}
	else
	{
		(*hist)[i] = ft_strdup(rl);
		if (!(*hist)[i])
			return (0);
		(*hist)[i + 1] = NULL;
	}
	return (1);
}

int	handle_hist(char ***hist, char *rl)
{
	if (!(*hist))
	{
		*hist = malloc(sizeof(char *) * (HIST_SIZE + 1));
		if (!hist)
			return (0);
		(*hist)[0] = NULL;
	}
	if (!add_hist(hist, rl))
		return (ft_free_arr(*hist, HIST_SIZE), 0);
	return (1);
}
