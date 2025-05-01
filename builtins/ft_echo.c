/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:00:14 by ylabussi          #+#    #+#             */
/*   Updated: 2025/05/01 18:42:15 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_echo(char **args, int fdout)
{
	int		endl;
	int		first;
	size_t	i;

	first = 0;
	endl = 0;
	if (arrlen((void **) args) > 1)
		endl = (ft_strncmp(args[1], "-n", 3) == 0);
	i = 1 + endl;
	while (args[i])
	{
		if (first)
			ft_putchar_fd(' ', fdout);
		first |= 1;
		ft_putstr_fd(args[i], fdout);
		i++;
	}
	if (!endl)
		ft_putchar_fd('\n', fdout);
	return (0);
}
