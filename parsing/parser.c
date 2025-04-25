/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:46:37 by malapoug          #+#    #+#             */
/*   Updated: 2025/04/25 18:27:35 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*replace_var(char *str, char *path, int *code)
{
	char	*new;
	int		i;
	int		j;

	j = 1;
	i = find_money(str);
	while (str[i + j] && str[i + j] != ' ' && ft_isalpha(str[i + j]))
		j++;
	new = ft_calloc(1, sizeof(char) \
		* (ft_strlen(str) - j + ft_strlen(path) + 1));
	if (!new)
		return (NULL);
	ft_strlcat(new, str, i);
	if (str[i] == '?')
	{
		if (!uh(new, code))
			return (NULL);
	}
	else if (str[i] == '\0' || str[i] == ' ' || str[i] == '"')
		ft_strlcat_mod(new, "$", 2);
	else
		ft_strlcat_mod(new, path, ft_strlen(path) + 1);
	ft_strlcat_mod(new, str + i + j, ft_strlen(str + i + j));
	new[ft_strlen(str) - j + ft_strlen(path) + 1] = '\0';
	return (new);
}

char	**handle_env(char **envp, char **split, int *code, int i)
{
	char	*path;
	char	*temp;

	path = NULL;
	while (split[i] && split[i][0] != '\'' \
		&& split[i][find_money(split[i])] != '\0')
	{
		if (ft_strnstr(split[i], "<<", 3))
			break ;
		path = getvar(split[i] + find_money(split[i]), envp);
		if (!path || split[i][find_money(split[i])] == '$')
			temp = replace_var(split[i], "", code);
		else
			temp = replace_var(split[i] + 1, path, code);
		if (!temp)
			return (ft_free_arr(split, arr_size(split)), NULL);
		free(split[i]);
		split[i] = temp;
		split = list_insert(split, tokenize(split[i], code), i);
		if (!split)
			return (NULL);
	}
	return (split);
}

t_parsed	*parse(char **envp, char *rl, int *code)
{
	char		**split;
	t_parsed	*parsed;
	int			i;

	split = tokenize(rl, code);
	if (!split && *code == 0)
		printf("Error while tokenizing\n");
	if (!split)
		return (NULL);
	i = -1;
	while (split && split[++i])
		handle_env(envp, split, code, i);
	if (!split && *code == 0)
		printf("Error while handling env vars\n");
	if (!split)
		return (NULL);
	if (!handle_redirections(split, code))
		return (NULL);
	else
		*code = 0;
	parsed = struct_maker(split, code);
	if (!parsed || !trimm_struct(parsed))
		return (NULL);
	show_t_parsed(parsed);
	return (parsed);
}
