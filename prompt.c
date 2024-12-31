/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:49:41 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/31 16:13:49 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_name(void)
{
	//envp : USER
	return (NULL);
}

char	*prompt(void)
{
	return(MAGENTA "\n┌─[NAME @ DEVICE]~[PATH]~o\n└─>" RESET);
}
/*
char	*prompt(void)
{
	char	*final;
	char	*name; //fonct a faire
	char	*device; //fonct a faire
	char	*path; //fonct a faire
	int		size;

	name = MAGENTA "NAME" RESET;
	device = MAGENTA "DEVICE" RESET;
	path = CYAN "PATH" RESET;
	size = ft_strlen(name) + ft_strlen(device) + ft_strlen(path) + 20;
	final = malloc(sizeof(char) * size);
	join(final, "\n┌─[");//check
	join(final, name);//check
	join(final, " @ ");//check
	join(final, device);//check
	join(final, "]~[");//check
	join(final, path);//check
	join(final, "]~o\n└─>");//check
	return (final);
}
*/
