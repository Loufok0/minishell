/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                           :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:19:03 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/09 15:07:49 by l              ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

//====================(INCLUDES)============================//
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../minishell.h"

//====================(DEFINES)=============================//

# define TMP_FILE ".msh_tmp"
# define METACHARSET "<>|?*[]$\\(){}\"'`&;=! +"
# define MSG_UNEXPECTED_NL "Syntax error near unexpected token `newline'"
# define MSG_UNEXPECTED_TOKEN "Syntax error near unexpected token `"
# define MSG_UNEXPECTED_LEFT_CHEVRON "Syntax error near unexpected token `<'"
# define MSG_UNEXPECTED_RIGHT_CHEVRON "Syntax error near unexpected token `>'"

//====================(STRUCTS)=============================//

typedef struct s_parsed
{
	char			**split;
	char			*infile;
	char			*outfile;
	int				out_mode;
	struct s_parsed	*next;
	int				fds[2];
	pid_t			pid;
}	t_parsed;

//====================(DECLARATIONS)========================//

//clean
void		free_chain(t_parsed *head);

//debug
void		show_arr(char **arr);
void		show_t_parsed(t_parsed *parsed);

//in_and_out
int			remove_in_out(t_parsed *head, int *code);
char		**in(t_parsed *node, char **split, int *code);
char		**out(t_parsed *node, char **split, int *code);

//in
char		**in_one(t_parsed *node, char **split, int *code, int i);
char		**in_two(t_parsed *node, char **split, int *code, int i);

//out
int			skip_ispaces(char **split, int i);
char		**out_one(t_parsed *node, char **split, int *code, int i);
char		**out_two(t_parsed *node, char **split, int *code, int i);

//limiter
int			get_line(char **line);
int			limiter(char *limiter);

//parser
t_parsed	*parse(char **envp, char *rl, int *code);
char		**handle_env(char **envp, char **split, int *code, int *i);
char		*replace_var(char *str, char *path, int *code);

//parser_utils
t_parsed	*trimm_struct(t_parsed *parsed);
char		*uh(char *neew, char *str, int *code, int i);
int			is_problem_char(char *str, int *code);
int			find_money(char *str);
char		*trimm(char *split);

//redirections
char		**handle_redirections(char **split, int *code);
char		**two(char **split, int *code, int i);

//struct
t_parsed	*struct_maker(char **split, int *code);

//tokenizer
char		**tokenize(char *rl, int *code);
void		remove_spaces(char **split, char *c);

//list_insert
char		**list_insert(char **lst1, char **lst2, int n);

//tokenizer_utils
char		**split_insert_arr(char ***split, int c);
char		**list_insert(char **lst1, char **lst2, int n);
void		duck_fishing(char **split, int i);
int			count_occ(char *str, int c);
int			total_occ(char **split, int c);
int			check_closed(char **split, int n);
int			check_follow(char **split, char *c);
t_parsed	*join_word(t_parsed *parsed);

//export_check
int			has_prob_char(char *str);
int			check_export(t_parsed *parsed);
char		**join_export(char **split);

#endif
