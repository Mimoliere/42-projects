/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 01:35:45 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/30 02:13:02 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

#include "../includes/get_next_line.h"
#include "../includes/get_next_line_bonus.h"

int	main(void)
{
	int		fd;
	char	*buffer;

	fd = open("file_to_read.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	buffer = get_next_line(fd);
	while (buffer)
	{
		printf("%s", buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	return (0);
}
