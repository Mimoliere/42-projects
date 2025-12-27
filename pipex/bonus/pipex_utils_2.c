/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:42:12 by bguerrou          #+#    #+#             */
/*   Updated: 2025/06/15 16:53:27 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../pipex_bonus.h"

int	opening(t_exec_params *params, char *filename, int i)
{
	if (i == 1)
		params->fd = open(filename, O_RDONLY);
	else
		params->fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (params->fd == -1)
		return (-1);
	return (0);
}

void	free_n_close(t_exec_params *params, int cmnd, int fd)
{
	free_arr(params->paths);
	if (cmnd == 1)
		free_arr(params->cmnd);
	if (fd == 1)
		close(params->fd);
	free(params);
}

void	close_fds(int *fds, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (fds[i] != -1)
			close(fds[i]);
		i++;
	}
}

void	clear_n_exit(t_exec_params *params, char *error)
{
	int	exitcode;

	exitcode = errno;
	if (params->pipe1)
		close_fds(params->pipe1, 2);
	if (params->pipe2)
		close_fds(params->pipe2, 2);
	free_n_close(params, 0, 0);
	
	perror(error);
	exit(exitcode);
}

void	start_waiting(int pid1, int pid2, int *pipefd, t_exec_params *params)
{
	int	status;

	status = 0;
	close_fds(pipefd, 2);
	waitpid(pid1, 0, 0);
	waitpid(pid2, &status, 0);
	if (status >= 255)
	{
		free_n_close(params, 0, 0);
		exit(1);
	}
}
