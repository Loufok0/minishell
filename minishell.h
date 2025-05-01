/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:41:26 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/01 16:48:46 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//====================(INCLUDES)============================//

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <signal.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "parsing/parsing.h"
# include "exec/exec.h"
# include "vars/vars.h"

//====================(DEFINES)=============================//

# define HIST_SIZE	100
# define METACHARSET "<>|?*[]$\\(){}\"'`&;=! "
# define TMP_FILE ".msh_tmp"
# define PROMPT "\033[34m\n<$$$> \033[0m"

//====================(STRUCTS)=============================//

//====================(DECLARATIONS)========================//

//envp
int		check11(char *temp, char *path);
int		check21(char **args, char *path);
char	*get_envp(char **envp, char *path);
int		find_envp(char **envp, char *path);
char	*get_path(char **envp, char *cmd);

//vars

size_t	addvar(char ***vars);
int		delvar(char const *var, char ***vars);
void	print_arr(char **arr, const char *name);

//lib_utils
char	*ft_strjoin_f(char *dst, char *src);
void	ft_free_arr(char **arr, int i);
void	ft_free_arr_i(int **arr, int i);
int		arr_size(char **arr);
int		arr_size_i(int **arr);
char	**ft_split_let(char const *s, char c);
char	**ft_arrdup(char **arr);
size_t	arrlen(void **a);

#endif
