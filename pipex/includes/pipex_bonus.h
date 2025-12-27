/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:15:15 by bguerrou          #+#    #+#             */
/*   Updated: 2025/06/15 16:57:12 by bguerrou         ###   ########.fr       */
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
	int		*pid;
	int		pipe1[2];
	int		pipe2[2];
}	t_exec_params;

int	process1(t_exec_params *params, char **argv,
	int *pipefd, char **envp);
int	process2(t_exec_params *params, char **argv,
	int *pipefd, char **envp);
int	before_process(t_exec_params *params, int argc, char **argv, char **envp);

void init_params(int argc, char **argv, char **envp, t_exec_params *params);

int		opening(t_exec_params *params, char *filename, int i);
void	free_arr(char **arr);
char	**set_command(char *argcmnd, char **paths,
			t_exec_params *params);
char	**parse_for_paths(char **envp, t_exec_params *params);
void	free_n_close(t_exec_params *params, int cmnd, int fd);
void	close_fds(int *fds, int size);
void	clear_n_exit(t_exec_params *params, char *error);
void	start_waiting(int pid1, int pid2, int *pipefd, t_exec_params *params);

#endif