/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:46:29 by malapoug          #+#    #+#             */
/*   Updated: 2025/04/24 17:01:17 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	uh(char *new, int *code)
{
	char	*nb;

	nb = ft_itoa(*code);
	if (!nb)
		return (free(new), 0);
	ft_strlcat_mod(new, nb, ft_strlen(nb) + 1);
	free(nb);
	return (1);
}

int	find_money(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i - 1] != '$' || str[i] == ' ' \
		|| str[i] == '"'))
		i++;
	return (i);
}

int	is_problem_char(char *str)
{
	if (str[0] == ')' \
		|| str[0] == '}' || str[0] == '<' || str[0] == '>' || str[0] == '|')
	{
		printf("Syntax error near unexpected token `%c'\n", (str[0]));
		return (1);
	}
	return (0);
}

char	*trimm(char *split)
{
	char	*temp;

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
