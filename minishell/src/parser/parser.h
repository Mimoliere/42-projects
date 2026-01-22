/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:38:50 by bguerrou          #+#    #+#             */
/*   Updated: 2025/08/20 13:23:32 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../include/minishell.h"
# include "../../include/structs.h"

// Parsing
t_tree	*transform(t_line *line, int prio, int limit, int exclude);

// Paths
char	**parse_for_paths(t_env *env, t_exec *ex);

#endif
