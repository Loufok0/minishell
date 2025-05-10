/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:27:56 by ylabussi          #+#    #+#             */
/*   Updated: 2025/05/10 16:33:29 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_unset(char **args, char ***envp)
{
	size_t	i;

	i = 0;
	if (arrlen((void **) args) < 2)
		return (EXIT_FAILURE);
	while (args[++i])
		delvar(args[i], envp);
	return (EXIT_SUCCESS);
}
