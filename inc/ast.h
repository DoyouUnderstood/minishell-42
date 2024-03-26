/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:38:40 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 15:11:12 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "redir_list.h"
# include "word_list.h"

typedef enum e_ast_type
{
	AST_AND,
	AST_OR,
	AST_PIPE,
	AST_SUBSHELL,
	AST_CMD
}	t_ast_type;

typedef struct s_ast_node
{
	t_ast_type			type;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
	t_redir_list		*redirections;
	t_word_list			*cmd_argv;
}	t_ast_node;

t_ast_node	*ast_create_binary(t_ast_type type, t_ast_node *left,
				t_ast_node *right);
t_ast_node	*ast_create_subshell(t_ast_node *left, t_redir_list	*redirections);
t_ast_node	*ast_create_cmd(t_redir_list *redirections, t_word_list *cmd_argv);
void		ast_destroy(t_ast_node *ast);
void		ast_foreach(t_ast_node *ast, void (*f)(t_ast_node *node, void *arg),
				void *arg);
t_ast_node	*ast_at(t_ast_node *ast, char *path);
void		ast_print(t_ast_node *ast, int margin);

#endif