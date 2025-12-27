/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:23:18 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/27 20:28:37 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/pipex.h"

static int	before_process(t_exec_params *params, char **argv, char **envp);
static int	process1(t_exec_params *params, char **argv,
				int *pipefd, char **envp);
static int	process2(t_exec_params *params, char **argv,
				int *pipefd, char **envp);

int	main(int argc, char **argv, char **envp)
{
	t_exec_params	params;

	if (argc != 5)
	{
		ft_putstr_fd("Wrong number of arguments (need 5).\n", STDERR_FILENO);
		exit(1);
	}
	if (before_process(&params, argv, envp) == -1)
	{
		ft_putstr_fd("Can't Malloc", 2);
		free_n_close(&params, 0, 0);
		exit(2);
	}
	free_n_close(&params, 0, 0);
	exit(0);
}

static int	before_process(t_exec_params *params, char **argv, char **envp)
{
	int		pipefd[2];

	params->paths = parse_for_paths(envp, params);
	if (!params->paths)
		return (-1);
	if (pipe(pipefd) == -1)
		clear_n_exit(params, "pipe", pipefd);
	params->pid1 = fork();
	if (params->pid1 == -1)
		clear_n_exit(params, "fork", pipefd);
	if (params->pid1 == 0)
	{
		if (process1(params, argv, pipefd, envp) == -1)
			return (close_fds(pipefd, 2), -1);
	}
	params->pid2 = fork();
	if (params->pid2 == -1)
		clear_n_exit(params, "fork", pipefd);
	if (params->pid2 == 0)
	{
		if (process2(params, argv, pipefd, envp) == -1)
			return (close_fds(pipefd, 2), -1);
	}
	start_waiting(params->pid1, params->pid2, pipefd, params);
	return (0);
}

static int	process1(t_exec_params *params, char **argv,
	int *pipefd, char **envp)
{
	if (opening(params, argv[1], 1) == -1)
		clear_n_exit(params, "open", pipefd);
	params->cmnd = set_command(argv[2], params->paths, params, pipefd);
	if (!params->cmnd)
		return (close(params->fd), -1);
	close(pipefd[0]);
	if (dup2(pipefd[1], 1) == -1 || dup2(params->fd, 0) == -1)
	{
		close(params->fd);
		free_arr(params->cmnd);
		clear_n_exit(params, "dup2", pipefd);
	}
	close(pipefd[1]);
	close(params->fd);
	free_arr(params->paths);
	if (execve(params->cmnd[0], params->cmnd, envp) == -1)
	{
		close(params->fd);
		free_arr(params->cmnd);
		clear_n_exit(params, "execve", pipefd);
	}
	return (0);
}

static int	process2(t_exec_params *params, char **argv,
	int *pipefd, char **envp)
{
	if (opening(params, argv[4], 4) == -1)
		clear_n_exit(params, "open", pipefd);
	params->cmnd = set_command(argv[3], params->paths, params, pipefd);
	if (!params->cmnd)
		return (close(params->fd), -1);
	close(pipefd[1]);
	if (dup2(pipefd[0], 0) == -1 || dup2(params->fd, 1) == -1)
	{
		close(params->fd);
		free_arr(params->cmnd);
		clear_n_exit(params, "dup2", pipefd);
	}
	close(pipefd[0]);
	close(params->fd);
	free_arr(params->paths);
	if (execve(params->cmnd[0], params->cmnd, envp) == -1)
	{
		close(params->fd);
		free_arr(params->cmnd);
		clear_n_exit(params, "execve", pipefd);
	}
	return (0);
}
