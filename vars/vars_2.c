/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:10:28 by ylabussi          #+#    #+#             */
/*   Updated: 2025/04/28 15:54:20 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"

/* returns the new env index to set immediately */
size_t	addvar(char ***vars)
{
	size_t	i;
	char	**new;

	i = arrlen((void **)(*vars)) + 1;
	new = malloc((i + 1) * sizeof(char *));
	if (!new)
		return (0);
	new[i] = NULL;
	ft_memmove(new, *vars, i * sizeof(char *));
	free(*vars);
	(*vars) = new;
	return (i);
}

int	delvar(char const *var, char ***vars)
{
	size_t	l;
	size_t	arl;
	size_t	i;
	char	**new;

	arl = arrlen((void **) *vars);
	l = ft_strlen(var);
	i = getvarid(var, l, *vars);
	if (i == arl)
		return (0);
	new = ft_calloc(arl, sizeof(char *));
	if (!new)
		return (1);
	ft_memmove(new, *vars, i * sizeof(char *));
	ft_memmove(&new[i], &(*vars)[i + 1], (arl - i) * sizeof(char *));
	free((*vars)[i]);
	free(*vars);
	*vars = new;
	return (0);
}

void	print_arr(char **arr, const char *name)
{
	size_t	i;

	i = 0;
	printf("%s[%li] = {\n", name, arrlen((void **) arr));
	while (arr[i])
		printf("\t\"%s\",\n", arr[i++]);
	printf("}\n");
}
