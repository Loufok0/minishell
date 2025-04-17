/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:41:26 by malapoug          #+#    #+#             */
/*   Updated: 2025/02/25 17:44:06 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//====================(INCLUDES)============================//

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "prompt/colors.h"
# include "parsing/parsing.h"
# include "libft/libft.h"

//====================(DEFINES)=============================//

# define HIST_SIZE	100

//====================(STRUCTS)=============================//

//====================(DECLARATIONS)========================//

//prompt
char	*prompt(char **envp);

//envp
int		check11(char *temp, char *path);
int		check21(char **args, char *path);
char	*get_envp(char **envp, char *path);
int		find_envp(char **envp, char *path);
char	*get_path(char **envp, char *cmd);

//lib_utils
char	*ft_strjoin_f(char *dst, char *src);
void	ft_free_arr(char **arr, int i);
void	ft_free_arr_i(int **arr, int i);
int		arr_size(char **arr);
int		arr_size_i(int **arr);
char	**ft_split_let(char const *s, char c);

#endif
