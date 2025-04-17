/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:46:37 by malapoug          #+#    #+#             */
/*   Updated: 2025/04/17 14:44:21 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*replace_var(char *str, char *path)
{
	char	*n;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i - 1] != '$')
		i++;
	while (str[i + j] && str[i + j] != ' ' && ft_isalpha(str[i + j]))
		j++;
	n = ft_calloc(1, sizeof(char) * (ft_strlen(str) - j + ft_strlen(path) + 1));
	if (!n)
		return (NULL);
	ft_strlcat(n, str, i);
	ft_strlcat_mod(n, path, ft_strlen(path) + 1);
	ft_strlcat_mod(n, str + i + j, ft_strlen(str + i + j));
	n[ft_strlen(str) - j + ft_strlen(path) + 1] = '\0';
	return (n);
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

char	**handle_env(char **envp, char **split, int *code)
{
	int		i;
	char	*path;
	char	*temp;

	i = -1;
	path = NULL;
	while (split[++i])
	{
		while (split[i] && split[i][0] != '\'' && count_occ(split[i], '$') != 0)
		{
			if (ft_strnstr(split[i], "<<", 3) \
					&& !ft_strnstr(split[i], "<<<", 4))
				break ;
			path = get_envp(envp, ft_strchr(split[i], '$') + 1);
			if (!path)
				temp = replace_var(split[i], "");
			else
				temp = replace_var(split[i], path + 1);
			if (!temp)
				return (ft_free_arr(split, arr_size(split)), NULL);
			free(split[i]);
			split[i] = temp;
			split = list_insert(split, tokenize(split[i], code), i);
			if (!split)
				return (NULL);
		}
	}
	return (split);
}

t_parsed	*parse(char **envp, char *rl, int *code)
{
	char		**split;
	t_parsed	*parsed;

	split = tokenize(rl, code);
	if (!split)
		return (printf("Error while tokenizing\n"), NULL);
	split = handle_env(envp, split, code);
	if (!split)
		return (printf("Error while handling env vars\n"), NULL);
	split = handle_redirections(split, code);
	if (!split)
		return (NULL);
	parsed = struct_maker(split, code);
	if (!parsed)
		return (NULL);
//	trimm(parsed->split);
	show_t_parsed(parsed);
	return (parsed);
}

//WARNING  "echo \$HOME"	>>	"$HOME"
