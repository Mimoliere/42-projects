/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:43:16 by bguerrou          #+#    #+#             */
/*   Updated: 2025/06/15 16:19:08 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"
#include "libft.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	**parse_for_paths(char **envp, t_exec_params *params)
{
	char	**paths;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			break ;
		i++;
	}
	if (!envp[i])
	{
		ft_putstr_fd("No Paths", 2);
		params->paths = NULL;
		free_n_close(params, 0, 0);
		exit(3);
	}
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

static void	no_command(char *cmnd, t_exec_params *params)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd("command not found: ", STDERR_FILENO);
	ft_putstr_fd(cmnd, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	close_fds(params->pipe1, 2);
	close_fds(params->pipe2, 2);
	free_n_close(params, 0, 1);
	exit(127);
}

static char	**cmnd_split(char *path, char *args)
{
	char	**cmnd;
	int		i;

	i = 0;
	while (args[i] != ' ' && args[i])
		i++;
	if (ft_strncmp(path, args, ft_strlen(path)) != 0)
	{
		path = altered_ft_strjoin(path, args + i);
		if (!path)
			return (NULL);
	}
	cmnd = ft_split(path, ' ');
	if (!cmnd)
		cmnd = NULL;
	free(path);
	return (cmnd);
}

char	**set_command(char *argcmnd, char **paths,
		t_exec_params *params)
{
	char	*path;
	char	*cmnd;

	cmnd = ft_cpytillsep(argcmnd, ' ');
	if (!cmnd)
		return (NULL);
	if (!ft_strncmp(cmnd, "", 1))
		return (free(cmnd), no_command(argcmnd, params), NULL);
	if ((!ft_strncmp(argcmnd, "./", 2) && !access(cmnd, X_OK))
		|| !access(cmnd, X_OK))
		return (cmnd_split(cmnd, argcmnd));
	while (*paths)
	{
		path = ft_strjoin(*(paths++), "/");
		if (!path)
			return (free(cmnd), NULL);
		path = altered_ft_strjoin(path, cmnd);
		if (!path)
			return (free(cmnd), NULL);
		if (access(path, X_OK) == 0)
			return (free(cmnd), cmnd_split(path, argcmnd));
		free(path);
	}
	return (free(cmnd), no_command(argcmnd, params), NULL);
}
