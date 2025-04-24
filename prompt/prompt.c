/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:49:41 by malapoug          #+#    #+#             */
/*   Updated: 2025/04/24 15:31:14 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "colors.h"

char	*prompt(char **envp)
{
	char	*final;
	char	*name;
	char	*path;

	name = getvar("LOGNAME", envp);
	path = getvar("PWD", envp);
	if (!name || !path)
		return (ft_strdup("$ "));
	final = ft_strjoin_f(NULL, "\n┌─[");
	final = ft_strjoin_f(final, MAGENTA);
	final = ft_strjoin_f(final, name);
	final = ft_strjoin_f(final, RESET);
	final = ft_strjoin_f(final, "]~[");
	final = ft_strjoin_f(final, CYAN);
	final = ft_strjoin_f(final, path);
	final = ft_strjoin_f(final, RESET);
	final = ft_strjoin_f(final, "]~o\n└─O ");
	return (final);
}
