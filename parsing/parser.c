/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:46:37 by malapoug          #+#    #+#             */
/*   Updated: 2025/02/24 00:26:31 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*replace_var(char *str, char *path)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '$')
		i++;
	while (str[i + j] && (str[i + j] != ' ' && str[i + j] != '\0' && str[i + j] != '$'))
		j++;
	new = ft_calloc(1, sizeof(char) * (ft_strlen(str) - j + ft_strlen(path) + 1));
	if (!new)
		return (NULL);
	ft_strlcat(new, str, i + 1);
	if (path)
		ft_strlcat_mod(new, path, ft_strlen(path) + 1);
	ft_strlcat_mod(new, str + i + j, ft_strlen(str + i + j));
	new[ft_strlen(str) - j + ft_strlen(path) + 1] = '\0';
	return (new);
}

char	**handle_env(char **envp, char **split)
{
	char	*path;
	char	*temp;
	int	i;

	i = -1;
	path = NULL;
	while (split[++i])
	{
		//if (ft_strchr(ft_strchr(split[i], '$') + 1, '$') != 0)//a faire
		//	path = get_envp(envp, "BASHPID=");
		if (split[i][0] != '\'' && count_occ(split[i], '$') != 0)
		{
			split[i] = ft_strtrim(split[i], "\"");
			path = get_envp(envp, ft_strchr(split[i], '$') + 1) + 1;
			if (find_envp(envp, ft_strchr(split[i], '$') + 1) == arr_size(envp))
				temp = replace_var(split[i], "");//free path
			else
				temp = replace_var(split[i], path);
			if (!temp)
				return (ft_free_arr(split, arr_size(split)), NULL);
			else
			{
				free(split[i]);
				split[i] = temp;
			}
		}
	}
	return (split);
}

char	**parse(char **envp, char *rl)
{
	char	**split;

	split = tokenize(rl);
	if (!split)
		return (NULL);
	split = handle_env(envp, split);
	show_arr(split);
	return (split);
}





//WARNING  "echo \$HOME"	>>	"$HOME"











/*
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

*/
