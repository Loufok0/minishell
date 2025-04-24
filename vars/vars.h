/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:17:00 by ylabussi          #+#    #+#             */
/*   Updated: 2025/04/24 15:31:57 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

# include "../minishell.h"

size_t	idlen(char const *s);
size_t	getvarid(const char *var, size_t l, char **vars);
char	*getvar(char const *var, char **vars);
int		setvar(char const *var, char ***vars);
int		setvar_join(char const *prefix, char const *val, char ***vars);

size_t	addvar(char ***vars);
int		delvar(char const *var, char ***vars);

#endif
