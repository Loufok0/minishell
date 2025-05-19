/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                           :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:57:27 by ylabussi          #+#    #+#             */
/*   Updated: 2025/05/19 17:44:18 by l              ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_exit(char **args, char ***envp, int oldstatus)
{
	int	exit_status;

	if (arrlen((void **) args) > 2)
	{
		ft_putendl_fd(MSG_TOO_MANY_ARGS, STDERR_FILENO);
		return (EXIT_NOT_FOUND);
	}
	if (*args)
	{
		exit_status = ft_atoi(*args);
	}
	else
		exit_status = oldstatus;
	ft_free_arr(*envp, arrlen((void **)(*envp)));
	*envp = NULL;
	return (exit_status);
}
