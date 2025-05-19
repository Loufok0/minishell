/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:00:50 by ylabussi          #+#    #+#             */
/*   Updated: 2025/05/06 14:58:31 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../exec/exec.h"

# define MSG_TOO_MANY_ARGS "exit: too many arguments"

int	is_builtin(const char *cmd);
int	exe_builtin(char **args, char ***envp, int oldstatus, int fdout);

int	ft_env(char **envp, int fdout);
int	ft_echo(char **args, int fdout);
int	ft_export(char **args, char ***envp, int fdout);
int	ft_pwd(char **envp, int fdout);
int	ft_cd(char **args, char ***envp, int fdout);
int	ft_unset(char **args, char ***envp);
int	ft_exit(char **args, char ***envp, int oldstatus);

#endif