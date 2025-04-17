/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:19:03 by malapoug          #+#    #+#             */
/*   Updated: 2025/04/17 13:38:43 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

//====================(INCLUDES)============================//
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../prompt/colors.h"

//====================(DEFINES)=============================//

//0 	Successful exit without errors
//1 	One or more generic errors encountered upon exit
//2 	Incorrect usage, such as invalid options or missing arguments
//126 	Command found but is not executable
//127 	Command not found, usually the result of a missing directory in $PATH variable
//128+N 	Command encountered fatal error (was forcefully terminated manually or from an outside source). The N tells us which signal was received (see example below)
//130 	Command terminated with signal 2 (SIGINT) (ctrl+c on keyboard). 128+2
//143 	Command terminated with signal 15 (SIGTERM) (kill command). 128+15

//====================(STRUCTS)=============================//
//
typedef struct s_parsed
{
	char			**split;
	char			*infile;
	char			*outfile;
	int				out_mode;
	struct s_parsed	*next;
}	t_parsed;

//====================(DECLARATIONS)========================//

//clean
void		free_chain(t_parsed *head);
void		free_chain(t_parsed *head);

//debug
void		show_arr(char **arr);
void		show_t_parsed(t_parsed *parsed);

//in_and_out
int			remove_in_out(t_parsed *head, int *code);
char		**in(t_parsed *node, char **split, int *code);
char		**out(t_parsed *node, char **split, int *code);

//limiter
int			get_line(char **line);
int			limiter(char *limiter);

//parser
t_parsed	*parse(char **envp, char *rl, int *code);
int			is_problem_char(char *str);
char		**handle_env(char **envp, char **split, int *code);
char		*replace_var(char *str, char *path);

//parser_utils
char		*trimm(char *split);

//redirections
char		**handle_redirections(char **split, int *code);
char		**two(char **split, int *code, int i);
char		**triple(char **split, int *code, int i);

//struct
t_parsed	*struct_maker(char **split, int *code);

//tokenizer
char		**tokenize(char *rl, int *code);

//tokenizer_utils
char		**split_insert_arr(char ***split, int c);

//tokenizer_utils
char		**list_insert(char **lst1, char **lst2, int n);
void		duck_fishing(char **split, int i);
int			count_occ(char *str, int c);
int			total_occ(char **split, int c);
int			check_closed(char **split, int n);
int			check_follow(char **split, char *c);

#endif
