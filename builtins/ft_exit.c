/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                           :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:57:27 by ylabussi          #+#    #+#             */
/*   Updated: 2025/05/21 18:24:20 by l              ########   odam.nl        */
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
	if (args[1])
	{
		exit_status = ft_atoi(args[1]);
		if (!ft_isdigit(args[1][0]))
		{
			ft_putstr_fd("exit: ", STDERR_FILENO);
			ft_putstr_fd(args[1], STDERR_FILENO);
			ft_putendl_fd(": numeric argument required", STDERR_FILENO);
			exit_status = 2;
		}
	}
	else
		exit_status = oldstatus;
	ft_free_arr(*envp, arrlen((void **)(*envp)));
	*envp = NULL;
	return (exit_status);
}
