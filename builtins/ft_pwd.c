/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:37:50 by ylabussi          #+#    #+#             */
/*   Updated: 2025/04/29 17:15:34 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd(char **envp)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	if (!buf)
	{
		buf = getvar("PWD", envp);
		if (buf)
		{
			ft_putendl_fd(buf, 1);
			return (EXIT_SUCCESS);
		}
		else
			return (EXIT_SYSERROR);
	}
	else
		ft_putendl_fd(buf, 1);
	free(buf);
	return (EXIT_SUCCESS);
}
