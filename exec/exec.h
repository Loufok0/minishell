/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:19:51 by ylabussi          #+#    #+#             */
/*   Updated: 2025/05/01 16:58:58 by malapoug         ###   ########.fr       */
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

int			exe_file(char *path, t_parsed *cmd, char **envp);
void		exe_cmd(t_parsed *cmd, int *status, char ***envp);
int			exe_pipeline_chain(t_parsed *cmd, int *status, char ***envp);
void		start_pipeline(t_parsed *cmd, char ***envp, int *status);
void		exe_pipeline(t_parsed *cmd, char ***envp, int *status);

char		*find_exe(char *cmd, char **envp);
char		*pathcat(const char *path, const char *rel);
int			open_pipe(t_parsed *cmd);
t_parsed	*getlast(t_parsed	*node);
void		print_error_msg(char *str, int status);

#endif
