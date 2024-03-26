/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:48:50 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 17:48:51 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INTERNAL_H
# define PARSE_INTERNAL_H

# include "ast.h"
# include "ft_error.h"
# include "heredoc_list.h"
# include "tl_scanner.h"

t_ast_node	*parse_and_or(t_tl_scanner *scanner, t_heredoc_list **heredocs,
				t_error *error);
t_ast_node	*parse_pipeline(t_tl_scanner *scanner, t_heredoc_list **heredocs,
				t_error *error);
t_ast_node	*parse_full_cmd(t_tl_scanner *scanner, t_heredoc_list **heredocs,
				t_error *error);

#endif