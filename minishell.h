/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:41:26 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/15 02:03:06 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//====================(INCLUDES)============================//

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
//# include "libft/libft.h"
# include "colors.h"

//====================(DEFINES)=============================//

# define HIST_SIZE	10

//====================(STRUCTS)=============================//

typedef struct s_token
{
	char	*str;
	char	*path;
	int	is_cmd;
	int	is_d_quoted;
	int	is_quoted;
	struct s_token	*next;
}	t_token;

//====================(DECLARATIONS)========================//

//prompt
char	*prompt(char **envp);

//parser
t_token	*parse(char **envp, char *rl);

//tokenizer
char	**tokenize(char *rl);

//parser_utils
char	**list_insert(char **lst1, char **lst2, int n);
void	duck_fishing(char **split, int i);
int		count_occ(char *str, int c);
int		total_occ(char **split, int c);
int		check_quotes(char **split, int c);

//envp
int		check11(char *temp, char *path);
int		check21(char **args, char *path);
char	*get_envp(char **envp, char *path);
int		find_envp(char **envp, char *path);
char	*get_path(char **envp, char *cmd);

//clean
void	free_t_token(t_token *head);

//lib_utils
char	*ft_strjoin_f(char *dst, char *src);
void	ft_free_arr(char **arr, int i);
void	ft_free_arr_i(int **arr, int i);
int		arr_size(char **arr);
int		arr_size_i(int **arr);
char	**ft_split_let(char const *s, char c);

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
