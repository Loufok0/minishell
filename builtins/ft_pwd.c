/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:37:50 by ylabussi          #+#    #+#             */
/*   Updated: 2025/05/01 17:12:15 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd(char **envp, int fdout)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	if (!buf)
	{
		buf = getvar("PWD", envp);
		if (buf)
		{
			ft_putendl_fd(buf, fdout);
			return (EXIT_SUCCESS);
		}
		else
			return (EXIT_SYSERROR);
	}
	else
		ft_putendl_fd(buf, fdout);
	free(buf);
	return (EXIT_SUCCESS);
}
