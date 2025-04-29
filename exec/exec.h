/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:19:51 by ylabussi          #+#    #+#             */
/*   Updated: 2025/04/29 15:54:19 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../builtins/builtins.h"
# include "../minishell.h"
# include <sys/stat.h>

# define EXIT_SYSERROR 125
# define EXIT_PERMISSION 126
# define EXIT_NOT_FOUND 127

typedef struct s_parsed	t_parsed;

size_t		arrlen(void **a);
char		*pathcat(const char *path, const char *rel);
void		exe_pipeline(t_parsed *cmd, char ***envp, int *status);
int			open_pipe(t_parsed *cmd);
t_parsed	*getlast(t_parsed *node);
char		*find_exe(char *cmd, char **envp);
int			exe_file(char *path, t_parsed *cmd, char **envp);

void		print_error_msg(char *str, int status);
void		child_process(t_parsed *cmd, int *status, char *path, char ***envp);

#endif