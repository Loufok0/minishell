/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:41:26 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/05 19:06:07 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//====================(INCLUDES)============================//

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

//====================(DEFINES)=============================//

# define HIST_SIZE	10

//====================(DECLARATIONS)========================//

//prompt
char	*prompt(char **envp);

//parser
char	**parse(char *rl);

//parser_utils
char	**list_insert(char **lst1, char **lst2, int n);
void	duck_fishing(char **split, int i);
int		count_occ(char *str, int c);
int		total_occ(char **split, int c);
int		check_quotes(char **split, int c);

//history
char	*get_prev_hist(char **hist, int ind);
void	shift_left(char ***arr);
int	add_hist(char ***hist, char *rl);
int	handle_hist(char ***hist, char *rl);

//envp
int		check11(char *temp, char *path);
int		check21(char **args, char *path);
char	*get_envp(char **envp, char *path);
int		find_envp(char **envp, char *path);
char	*get_path(char **envp, char *cmd);

//debug
void	show_arr(char **arr);

//====================(COLORS)==============================//

// Réinitialisation
# define RESET       "\033[0m"

// Couleurs de texte
# define BLACK       "\033[30m"
# define RED         "\033[31m"
# define GREEN       "\033[32m"
# define YELLOW      "\033[33m"
# define BLUE        "\033[34m"
# define MAGENTA     "\033[35m"
# define CYAN        "\033[36m"
# define WHITE       "\033[37m"

// Couleurs de fond
# define BG_BLACK    "\033[40m"
# define BG_RED      "\033[41m"
# define BG_GREEN    "\033[42m"
# define BG_YELLOW   "\033[43m"
# define BG_BLUE     "\033[44m"
# define BG_MAGENTA  "\033[45m"
# define BG_CYAN     "\033[46m"
# define BG_WHITE    "\033[47m"

// Styles
# define BOLD        "\033[1m"
# define UNDERLINE   "\033[4m"
# define BLINK       "\033[5m"

#endif
