/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:46:29 by malapoug          #+#    #+#             */
/*   Updated: 2025/04/13 11:42:56 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*trimm(char *split)
{
	char	*temp;

	if (split[0] == '\'')
	{
		temp = ft_strtrim(split, "'");
		free(split);
		split = temp;
	}
	else if (split[0] == '"')
	{
		temp = ft_strtrim(split, "\"");
		free(split);
		split = temp;
	}
	return (split);
}
