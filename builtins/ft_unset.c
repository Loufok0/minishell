/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:27:56 by ylabussi          #+#    #+#             */
/*   Updated: 2025/05/02 17:03:44 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_unset(char **args, char ***envp)
{
	if (arrlen((void **) args) < 2)
		return (EXIT_FAILURE);
	return (delvar(args[1], envp));
}
