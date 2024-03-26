/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:39:38 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 16:39:39 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "exec_internal.h"

#include "ast.h"
#include "global.h"

int	exec_ast(t_ast_node *ast)
{
	int	exit_status;

	if (!ast)
		exit_status = 0;
	else if (ast->type == AST_AND)
		exit_status = exec_and(ast);
	else if (ast->type == AST_OR)
		exit_status = exec_or(ast);
	else if (ast->type == AST_PIPE)
		exit_status = exec_pipeline(ast);
	else if (ast->type == AST_SUBSHELL)
		exit_status = exec_simple_subshell(ast);
	else if (ast->type == AST_CMD)
		exit_status = exec_simple_cmd(ast);
	else
		exit_status = 0;
	last_exit_status(exit_status);
	return (exit_status);
}
