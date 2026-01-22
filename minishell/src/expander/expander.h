/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:12:58 by bguerrou          #+#    #+#             */
/*   Updated: 2025/08/20 13:22:19 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "../../include/minishell.h"

// Expanding
char	*expand(char *str, t_shell *shell, t_line *line, int mode);

// Expanding utilss
int		till_sep(char *str);
int		change_mode(char c, int *mode);
char	*var_name(char *str);

#endif