/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:57:27 by ylabussi          #+#    #+#             */
/*   Updated: 2025/05/08 16:21:59 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	exit_input_check(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_exit(char *status, char ***envp, int oldstatus)
{
	int	exit_status;

	if (status)
	{
		if (exit_input_check(status))
		{
			exit_status = 2;
			ft_putstr_fd("exit: ", STDERR_FILENO);
			ft_putstr_fd(status, STDERR_FILENO);
			ft_putendl_fd(": numeric argument required", STDERR_FILENO);
		}
		else
			exit_status = ft_atoi(status);
	}
	else
		exit_status = oldstatus;
	ft_free_arr(*envp, arrlen((void **)(*envp)));
	*envp = NULL;
	return (exit_status);
}
