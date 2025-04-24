/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabussi <ylabussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:20:03 by ylabussi          #+#    #+#             */
/*   Updated: 2025/04/24 15:33:45 by ylabussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*find_exe(char *cmd, char **envp)
{
	char	**paths;
	char	*exe;
	size_t	i;

	i = 0;
	if (ft_strchr("/.~", cmd[0]))
		return (ft_strdup(cmd));
	paths = ft_split(getvar("PATH", envp), ':');
	if (!paths)
		return (NULL);
	exe = NULL;
	while (paths[i])
	{
		exe = pathcat(paths[i], cmd);
		i++;
		if (!exe)
			continue ;
		else if (access(exe, F_OK) == 0)
			break ;
		free(exe);
		exe = NULL;
	}
	ft_free_arr(paths, arrlen((void **) paths));
	return (exe);
}

char	*pathcat(const char *path, const char *rel)
{
	size_t	len;
	int		addsep;
	char	*new;

	len = ft_strlen(path);
	addsep = (path[len - 1] != '/');
	if (addsep)
		len++;
	len += ft_strlen(rel);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, path, len + 1);
	ft_strlcat(new, "/", len + 1);
	ft_strlcat(new, rel, len + 1);
	return (new);
}

int	open_pipe(t_parsed *cmd)
{
	int	pfds[2];

	if (cmd->next)
	{
		if (pipe(pfds) == 0)
		{
			cmd->fds[1] = pfds[1];
			cmd->next->fds[0] = pfds[0];
		}
		else
			return (1);
	}
	return (0);
}

t_parsed	*getlast(t_parsed	*node)
{
	if (node && node->next)
		return (getlast(node->next));
	else
		return (node);
}
