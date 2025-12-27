/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:23:18 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/27 16:56:01 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_exec_params	*params;

	if (argc < 5)
	{
		ft_putstr_fd("Wrong number of arguments (need  at least 5).\n", STDERR_FILENO);
		exit(1);
	}
	init_params(argc, argv, envp, params);
	
	if (before_process(params, argc, argv, envp) == -1)
	{
		clear_n_exit(params, "Can't Malloc");
		exit(2);
	}
	free_n_close(params, 0, 0);
	exit(0);
}
