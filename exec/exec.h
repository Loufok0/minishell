/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:19:51 by ylabussi          #+#    #+#             */
/*   Updated: 2025/05/10 18:01:23 by ylabussi         ###   ########.fr       */
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

# define MSG_NOT_FOUND ": No such file or directory\n"
# define MSG_PERM ": Permission denied\n"
# define MSG_DIR ": Is a directory\n"
# define MSG_NOT_DIR ": Is not a directory\n"
# define MSG_MISSING_ARG ": filename argument required\n"

typedef struct s_parsed	t_parsed;

int			exe_file(char *path, t_parsed *cmd, char **envp);
int			exe_cmd(t_parsed *cmd, int *status, char ***envp, t_parsed *head);
int			exe_pipeline_chain(t_parsed *cmd, int *status, char ***envp, t_parsed *head);
void		start_pipeline(t_parsed *cmd, char ***envp, int *status);
void		exe_pipeline(t_parsed *cmd, char ***envp, int *status);

char		*find_exe(char *cmd, char **envp);
char		*pathcat(const char *path, const char *rel);
int			open_pipe(t_parsed *cmd);
t_parsed	*getlast(t_parsed	*node);
int			path_check(char *path, char mode, char *str);

#endif
