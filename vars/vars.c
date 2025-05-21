/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:03:15 by ylabussi          #+#    #+#             */
/*   Updated: 2025/05/21 19:03:02 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	idlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] && !ft_strchr(METACHARSET, s[i]))
		i++;
	return (i);
}

size_t	getvarid(const char *var, size_t l, char **vars)
{
	size_t	i;

	i = 0;
	while (vars[i] && (ft_strncmp(vars[i], var, l) || (var[l] && vars[i][l] != var[l])))
		i++;
	return (i);
}

char	*getvar(char const *var, char **vars)
{
	size_t	i;
	size_t	l;
	char	*r;

	r = NULL;
	l = idlen(var);
	i = getvarid(var, l, vars);
	if (vars[i] && vars[i][l] == '=')
		r = vars[i] + l + 1;
	return (r);
}

int	setvar(char const *var, char ***vars)
{
	size_t	i;
	char	*new;

	new = ft_strdup((char *) var);
	if (!new)
		return (1);
	i = getvarid(var, idlen(var), *vars);
	if ((*vars)[i])
	{
		free((*vars)[i]);
		(*vars)[i] = new;
	}
	else
	{
		if (addvar(vars) == i)
			(*vars)[i] = new;
		else
		{
			free(new);
			return (1);
		}
	}
	return (0);
}

int	setvar_join(char const *prefix, char const *val, char ***vars)
{
	size_t	i;
	char	*new;

	new = ft_strjoin((char *) prefix, (char *) val);
	if (!new)
		return (1);
	i = getvarid(new, idlen(new), *vars);
	if ((*vars)[i])
	{
		free((*vars)[i]);
		(*vars)[i] = new;
	}
	else
	{
		if (addvar(vars) == i + 1)
			(*vars)[i] = new;
		else
		{
			free(new);
			return (1);
		}
	}
	return (0);
}
