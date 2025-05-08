/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:46:29 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/08 16:22:57 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*uh(char *new, char *str, int *code, int i)
{
	char	*nb;

	nb = ft_itoa(*code);
	if (!nb)
		return (NULL);
	new = ft_calloc(1, sizeof(char) \
		* (ft_strlen(str) - 2 + ft_strlen(nb) + 1));
	if (!new)
		return (NULL);
	ft_strlcat(new, str, i);
	ft_strlcat(new, nb, ft_strlen(nb) + 1);
	ft_strlcat_mod(new, str + i + 1, ft_strlen(str + i + 2));
	free(nb);
	return (new);
}

int	find_money(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ((str[i] == '$' && str[i + 1] && \
		str[i + 1] != '$') || str[i] == ' ' || str[i] == '"'))
		i++;
	return (i);
}

int	is_problem_char(char *str, int *code)
{
	if (str[0] == ')' \
		|| str[0] == '}' || str[0] == '<' || str[0] == '>' || str[0] == '|')
	{
		*code = 2;
		printf("Syntax error near unexpected token `%c'\n", (str[0]));
		return (1);
	}
	return (0);
}

char	*trimm(char *split)
{
	char	*temp;

	if (!split)
		return (NULL);
	if (split[0] == '\'')
	{
		temp = ft_strtrim(split, "'");
		if (!temp)
			return (NULL);
		free(split);
		split = temp;
	}
	else if (split[0] == '"')
	{
		temp = ft_strtrim(split, "\"");
		if (!temp)
			return (NULL);
		free(split);
		split = temp;
	}
	return (split);
}

t_parsed	*trimm_struct(t_parsed *parsed)
{
	t_parsed	*temp;
	int			i;

	temp = parsed;
	while (temp)
	{
		i = 0;
		while (temp->split[i])
		{
			temp->split[i] = trimm(temp->split[i]);
			if (!temp->split[i])
				return (free_chain(parsed), NULL);
			i++;
		}
		temp = temp->next;
	}
	return (parsed);
}
