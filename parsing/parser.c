/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:46:37 by malapoug          #+#    #+#             */
/*   Updated: 2025/05/10 16:49:20 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*replace_path(char *str, char *path, int i, int j)
{
	char	*new;

	new = ft_calloc(1, sizeof(char) \
		* (ft_strlen(str) - j + ft_strlen(path) + 1));
	if (!new)
		return (NULL);
	ft_strlcat(new, str, i + 1);
	if (str[i + 1] == '\0' || str[i] == ' ' || str[i] == '"')
		ft_strlcat_mod(new, "$", 2);
	else
		ft_strlcat_mod(new, path, ft_strlen(path) + 1);
	new = ft_strjoin_f(new, str + i + j);
	return (new);
}

char	*replace_var(char *str, char *path, int *code)
{
	char	*new;
	int		i;
	int		j;

	new = NULL;
	j = 1;
	i = find_money(str);
	while (str[i + j] && str[i + j] != ' ' && ft_isalpha(str[i + j]))
		j++;
	if (str[i + 1] == '?')
	{
		new = uh(new, str, code, i);
		if (!new)
			return (NULL);
	}
	else
		new = replace_path(str, path, i, j);
	return (new);
}

int	skip_rev(char **split, int i)
{
	if (!split[i])
		return (i);
	while (i > 0 && split[i] && (split[i][0] \
		&& split[i][0] == ' ' && split[i][1] == '\0'))
		i--;
	return (i);
}

char	**handle_env(char **envp, char **split, int *code, int *i)
{
	char	*path;
	char	*temp;

	path = NULL;
	while (split[*i] && ft_strchr(split[*i], '$') \
		&& split[*i][find_money(split[*i])] != '\0' && split[*i][0] != '\'')
	{
		if (*i > 1 && !ft_strncmp(split[skip_rev(split, (*i - 1))], "<<", 3))
			break ;
		path = getvar(ft_strchr(split[*i], '$') + 1, envp);
		if (!path || split[*i][find_money(split[*i]) + 1] == '$')
			temp = replace_var(split[*i], "", code);
		else
			temp = replace_var(split[*i], path, code);
		if (!temp)
			return (ft_free_arr(split, arr_size(split)), NULL);
		free(split[*i]);
		split[*i] = temp;
		split = list_insert(split, tokenize(split[*i], code), *i);
		if (!split)
			return (NULL);
	}
	if (!split[*i])
		(*i)--;
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
	if (!split || !handle_redirections(split, code))
		return (NULL);
	while (split && split[++i])
		split = handle_env(envp, split, code, &i);
	if (!split && *code == 0)
		printf("Error while handling env vars\n");
	if (!split)
		return (NULL);
	remove_spaces(split, "");
	parsed = struct_maker(split, code);
	if (!parsed)
		return (NULL);
	if (!parsed || !trimm_struct(parsed) || !join_word(parsed))
		return (NULL);
	return (parsed);
}
