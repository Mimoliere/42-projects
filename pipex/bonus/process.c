/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:20:21 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/27 16:56:01 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/pipex_bonus.h"

int	process1(t_exec_params *params, char **argv,
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
	if (execve(params->cmnd[0], params->cmnd, envp) == -1)
	{
		close(params->fd);
		free_arr(params->cmnd);
		clear_n_exit(params, "execve", pipefd);
	}
	return (0);
}

int	process2(t_exec_params *params, char **argv,
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
	if (execve(params->cmnd[0], params->cmnd, envp) == -1)
	{
		close(params->fd);
		free_arr(params->cmnd);
		clear_n_exit(params, "execve", pipefd);
	}
	return (0);
}

int	read_file(t_exec_params *params, char **argv, char **envp)
{
	if (opening(params, argv[1], 1) == -1)
		clear_n_exit(params, "open");
	params->cmnd = set_command(argv[2], params->paths, params);
	if (!params->cmnd)
		return (close(params->fd), -1);
	close(params->pipe1[0]);
	close(params->pipe2[0]);
	close(params->pipe2[1]);
	if (dup2(params->fd, 0) == -1 || dup2(params->pipe1[1], 1) == -1)
	{
		close(params->fd);
		free_arr(params->cmnd);
		clear_n_exit(params, "dup2");
	}
	if (execve(params->cmnd[0], params->cmnd, envp) == -1)
	{
		close(params->fd);
		free_arr(params->cmnd);
		clear_n_exit(params, "execve");
	}
	return (0);
}

int	pipe_read(t_exec_params *params, char *cmnd, char **envp, int pipe[2])
{
	params->cmnd = set_command(cmnd, params->paths, params);
	if (!params->cmnd)
		return (-1);
	close(params->pipe1[1]);
	close(params->pipe2[0]);
	if (dup2(params->pipe1[0], 0) == -1 || dup2(params->pipe2[1], 1))
	{
		free_arr(params->cmnd);
		clear_n_exit(params, "dup2");
	}
	if (execve(params->cmnd[0], params->cmnd, envp) == -1)
	{
		free_arr(params->cmnd);
		clear_n_exit(params, "execve");
	}
	return (0);
}

int	write_file(t_exec_params *params, int argc, char **argv, char **envp)
{
	if (opening(params, argv[argc - 1], 0) == -1)
		clear_n_exit(params, "open");
	params->cmnd = set_command(argv[argc - 2], params->paths, params);
	if (!params->cmnd)
		return (close(params->fd), -1);
	close(params->pipe2[1]);
	if (dup2(params->pipe2[0], 0) == -1 || dup2(params->fd, 1) == -1)
	{
		close(params->fd);
		free_arr(params->cmnd);
		clear_n_exit(params, "dup2");
	}
	if (execve(params->cmnd[0], params->cmnd, envp) == -1)
	{
		close(params->fd);
		free_arr(params->cmnd);
		clear_n_exit(params, "execve");
	}
	return (0);
}

int	before_process(t_exec_params *params, int argc, char **argv, char **envp)
{
	int	i;

	i = 0;
	params->pid[i] = fork();
	if (params->pid[i] == -1)
		clear_n_exit(params, "fork");
	if (params->pid[i++] == 0)
		if (read_file(params, argv, envp) == -1)
			return (-1);
	while (i < argc - 3)
	{
		params->pid[i] = fork();
		if (params->pid[i] == -1)
			clear_n_exit(params, "fork");
		if (params->pid[i++] == 0)
			
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
