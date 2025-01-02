/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:49:41 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/02 17:32:02 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_name(void)
{
	//envp : USER
	return (NULL);
}

/*
char	*prompt(void)
{
	return(MAGENTA "\n┌─[NAME @ DEVICE]~[PATH]~o\n└─>" RESET);
}
*/

char	*prompt(void)
{
	char	*final;
	char	*name; //fonct a faire
	char	*device; //fonct a faire
	char	*path; //fonct a faire

	name = MAGENTA "NAME" RESET;
	device = MAGENTA "DEVICE" RESET;
	path = CYAN "PATH" RESET;
	final = ft_strjoin_f(NULL, "\n┌─[");//check
	final = ft_strjoin_f(final, name);//check
	final = ft_strjoin_f(final, " @ ");//check
	final = ft_strjoin_f(final, device);//check
	final = ft_strjoin_f(final, "]~[");//check
	final = ft_strjoin_f(final, path);//check
	final = ft_strjoin_f(final, "]~o\n└─>");//check
	return (final);
}
