/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:22:46 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/27 16:56:01 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/pipex_bonus.h"

void init_params(int argc, char **argv, char **envp, t_exec_params *params)
{
    params = malloc(sizeof(t_exec_params));
    if (!params)
    {
        ft_putstr_fd("Can't Malloc", 2);
        exit(2);
    }
    params->pid = malloc(sizeof(int) * (argc - 3));
    if (!params->pid)
    {
        ft_putstr_fd("Can't Malloc", 2);
        free(params);
        exit(2);
    }
    params->paths = parse_for_paths(envp, params);
	if (!params->paths)
	{
        ft_putstr_fd("Can't Malloc", 2);
        free(params->pid);
        free(params);
        exit(2);
    }
    if (pipe(params->pipe1) == -1 || pipe(params->pipe2) == -1)
		clear_n_exit(params, "pipe");
}
