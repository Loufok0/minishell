/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:59:34 by ylabussi          #+#    #+#             */
/*   Updated: 2025/05/01 17:12:27 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_env(char **envp, int fdout)
{
	size_t	i;

	i = 0;
	while (envp[i])
		ft_putendl_fd(envp[i++], fdout);
	return (0);
}
