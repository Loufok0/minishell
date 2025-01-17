/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:49:41 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/17 16:57:04 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "colors.h"

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

char	*prompt(char **envp)
{
	char	*final;
	char	*name; //fonct a faire
	char	*path; //fonct a faire

	name = get_envp(envp, "LOGNAME=");
	path = getcwd(NULL, 0);
	final = ft_strjoin_f(NULL, "\n┌─[");//check
	final = ft_strjoin_f(final, MAGENTA);//check
	final = ft_strjoin_f(final, name);//check
	final = ft_strjoin_f(final, RESET);//check
	final = ft_strjoin_f(final, "]~[");//check
	final = ft_strjoin_f(final, CYAN );//check
	final = ft_strjoin_f(final, path );//check
	final = ft_strjoin_f(final, RESET );//check
	final = ft_strjoin_f(final, "]~o\n└─>");//check
	//final = ft_strjoin_f(final, BG_BLUE );//check
	free(path);
	return (final);
}
