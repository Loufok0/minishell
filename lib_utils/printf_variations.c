/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   printf_variations.c                                 :+:    :+:           */
/*                                                      +:+                   */
/*   By: l <l@student.42.fr>                           +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/05/21 18:44:10 by l              #+#    #+#                */
/*   Updated: 2025/05/21 18:44:37 by l              ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	printf_fd(char *s1, char *arg, char *s2, int fd)
{
	ft_putstr_fd(s1, fd);
	ft_putstr_fd(arg, fd);
	ft_putendl_fd(s2, fd);
}

void	print_fd(char *s1, char arg, char *s2, int fd)
{
	ft_putstr_fd(s1, fd);
	ft_putchar_fd(arg, fd);
	ft_putendl_fd(s2, fd);
}
