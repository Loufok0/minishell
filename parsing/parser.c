/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:46:37 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/07 15:28:37 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	init_token(t_token **token)
{
	(*token) = malloc(sizeof(t_token));
	if (!(*token))
		return (0);
	(*token)->str = NULL;
	(*token)->path = NULL;
	(*token)->is_cmd = 0;
	(*token)->is_d_quoted = 0;
	(*token)->is_quoted = 0;
	(*token)->next = NULL;
	return (1);
}

t_token	*list_const(char **envp, char **split)
{
	t_token	*lst;
	t_token	*current;
	int	i;

	if (!init_token(&lst))
		return (NULL);
	current = lst;
	i = -1;
	while (split[++i])
	{
		current->str = ft_strdup(split[i]);//check
		if (!current->str)
			return (NULL);
		current->path = get_path(envp, split[i]); //gerer pour enlever les "
		if (current->path != NULL)
			current->is_cmd = 1;
		if (!init_token(&(current->next)))
			return (NULL);//ft_free_t_token a faire
		current = current->next;
	}
	return (lst);
}

t_token	*parse(char **envp, char *rl)
{
	char	**split;
	t_token	*lst;

	lst = NULL;
	split = tokenize(rl);
	if (!split)
		return(NULL);
	lst = list_const(envp, split);
	return (ft_free_arr(split, arr_size(split)), lst);
}
