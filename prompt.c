/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:49:41 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/31 15:28:53 by malapoug         ###   ########.fr       */
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
	int		size;

	name = MAGENTA "NAME" RESET;
	device = MAGENTA "DEVICE" RESET;
	path = CYAN "PATH" RESET;
	size = ft_strlen(name) + ft_strlen(device) + ft_strlen(path) + 16;
	final = malloc(sizeof(char) * size);
	ft_strlcat(final, "\n┌─[", 3);//check
	ft_strlcat(final, name, ft_strlen(name));//check
	ft_strlcat(final, " @ ", 3);//check
	ft_strlcat(final, device, ft_strlen(device));//check
	ft_strlcat(final, "]~[", 3);//check
	ft_strlcat(final, path, ft_strlen(path));//check
	ft_strlcat(final, "]~o\n└─>", 6);//check
	ft_putstr_fd("ertggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg", 2);//trouver pourquoi ca marche pas
	return (final);
}
