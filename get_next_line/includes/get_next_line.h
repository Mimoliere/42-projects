/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:04:39 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/01 01:38:28 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 10

# endif

char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_has_char(char *str, char c);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *s, int c);

#endif