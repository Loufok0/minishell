/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:49:41 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/28 23:43:10 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_name(void)
{
	//echo whoami ?
	return (NULL);
}

char	*prompt(void)
{
	char	*final;
	char	*name; //fonct a faire
	char	*device; //fonct a faire
	char	*path; //fonct a faire

	name = MAGENTA "NAME" RESET;
	device = MAGENTA "DEVICE" RESET;
	path = CYAN "PATH" RESET;
	final = ft_strjoin("\n┌─[", name);
	final = ft_strjoin(final, " @ ");
	final = ft_strjoin(final, device);
	final = ft_strjoin(final, "]~[");
	final = ft_strjoin(final, path);
	final = ft_strjoin(final, "]~o\n└─>");
	return (final);
}
