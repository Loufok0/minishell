/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:12:59 by ylabussi          #+#    #+#             */
/*   Updated: 2025/04/29 17:20:33 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_export(char **args, char ***envp)
{
	size_t	l;
	int		r;

	l = arrlen((void **) args);
	if (l < 2)
		r = ft_env(*envp);
	else if (l == 2)
		r = setvar(args[1], envp);
	else if (l == 3)
		r = setvar_join(args[1], args[2], envp);
	else
		r = EXIT_FAILURE;
	return (r);
}
