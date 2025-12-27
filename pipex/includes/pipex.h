/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:41:49 by bguerrou          #+#    #+#             */
/*   Updated: 2025/02/28 13:54:55 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef struct params
{
	char	**cmnd;
	char	**paths;
	int		fd;
	int		pid1;
	int		pid2;
}	t_exec_params;

int		opening(t_exec_params *params, char *filename, int i);
void	free_arr(char **arr);
char	**set_command(char *argcmnd, char **paths,
			t_exec_params *params, int *pipefd);
char	**parse_for_paths(char **envp, t_exec_params *params);
void	free_n_close(t_exec_params *params, int cmnd, int fd);
void	close_fds(int *fds, int size);
void	clear_n_exit(t_exec_params *params, char *error, int *fds);
void	start_waiting(int pid1, int pid2, int *pipefd, t_exec_params *params);

#endif