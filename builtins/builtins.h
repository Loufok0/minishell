/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:00:50 by ylabussi          #+#    #+#             */
/*   Updated: 2025/04/29 16:25:14 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../exec/exec.h"

int	is_builtin(const char *cmd);
int	exe_builtin(char **args, char ***envp, int oldstatus);

int	ft_env(char **envp);
int	ft_echo(char **args);
int	ft_export(char **args, char ***envp);
int	ft_pwd(void);
int	ft_cd(char **args, char ***envp);
int	ft_unset(char **args, char ***envp);
int	ft_exit(char *status, char ***envp, int oldstatus);

#endif