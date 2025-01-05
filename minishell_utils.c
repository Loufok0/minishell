/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:45:36 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/05 14:09:38 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check11(char *temp, char *path)
{
	if (!temp && path)
		free(path);
	if (!path && temp)
		free(temp);
	if (!temp || !path)
		return (0);
	return (1);
}

int	check21(char **args, char *path)
{
	if (!args && path)
		free(path);
	if (!path && args)
		ft_free_arr(args, arr_size(args));
	if (!args || !path)
		return (0);
	return (1);
}

int	find_envp(char **envp, char *path)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], path, ft_strlen(path)) == 0)
			break ;
		i++;
	}
	return (i);
}

char	*get_envp(char **envp, char *path)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], path, ft_strlen(path)) == 0)
			break ;
		i++;
	}
	return (envp[i] + ft_strlen(path));
}

char	*get_path(char **envp, char *cmd)
{
	char	**paths;
	char	*cmd_path;
	char	*temp;
	int		i;

	cmd_path = NULL;
	paths = ft_split(envp[find_envp(envp, "PATH=")] + 5, *":");
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(temp, cmd);
		if (!check11(temp, cmd_path))
			return (ft_free_arr(paths, arr_size(paths)), NULL);
		free(temp);
		if (access(cmd_path, X_OK) == 0)
			break ;
		free(cmd_path);
		cmd_path = NULL;
		i++;
	}
	ft_free_arr(paths, arr_size(paths));
	return (cmd_path);
}
