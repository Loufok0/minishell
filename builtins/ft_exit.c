/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:57:27 by ylabussi          #+#    #+#             */
/*   Updated: 2025/05/10 16:43:27 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_exit(char *status, char ***envp, int oldstatus)
{
	int	exit_status;

	if (status)
	{
		exit_status = ft_atoi(status);
	}
	else
		exit_status = oldstatus;
	ft_free_arr(*envp, arrlen((void **)(*envp)));
	*envp = NULL;
	return (exit_status);
}
