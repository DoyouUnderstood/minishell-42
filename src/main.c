/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:31:45 by alletond          #+#    #+#             */
/*   Updated: 2024/03/26 19:05:34 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include "ast.h"
#include "env.h"
#include "exec.h"
#include "ft_error.h"
#include "heredoc_list.h"
#include "libft.h"
#include "parse.h"
#include "global.h"
#include "token_list.h"
#include "tokenize.h"
#include "ft_signal.h"
#include <signal.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

static void	init(char **argv, char **envp)
{
	prog_name(argv[0]);
	if (env_init(envp) != 0)
	{
		ft_error_print_system(prog_name(NULL), NULL);
		exit(1);
	}
	enable_raw_mode();
}

static char	*handle_readline(void)
{
	char	*line;

	line = readline("minishell> ");
	if (!line)
		exit(0);
	if (*line)
		add_history(line);
	return (line);
}

static t_ast_node	*build_ast(char *line, t_heredoc_list **heredocs)
{
	t_token_list	*tokens;
	t_error			*error;
	t_ast_node		*ast;

	error = ft_error_create();
	ast = NULL;
	if (!error)
	{
		ft_error_print_system(prog_name(NULL), NULL);
		return (NULL);
	}
	tokens = tokenize(line, error);
	if (!ft_has_error(error))
		ast = parse(tokens, heredocs, error);
	token_list_destroy(tokens);
	if (ft_has_error(error))
	{
		ft_error_print(prog_name(NULL), NULL, error);
		ft_error_destroy(error);
		heredoc_list_destroy(*heredocs);
		return (NULL);
	}
	return (ast);
}

static int	handle_heredocs(t_heredoc_list *heredocs, t_ast_node *ast)
{
	int	heredoc_result;

	signal_ignore_sigint();
	heredoc_result = heredoc_list_read(heredocs);
	heredoc_list_destroy(heredocs);
	if (heredoc_result != 0)
	{
		ast_destroy(ast);
		if (heredoc_result == -1)
			ft_error_print_system(prog_name(NULL), NULL);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char			*line;
	t_ast_node		*ast;
	t_heredoc_list	*heredocs;

	(void) argc;
	init(argv, envp);
	while (1)
	{
		signal_sigint_replay();
		line = handle_readline();
		heredocs = NULL;
		ast = build_ast(line, &heredocs);
		free(line);
		if (!ast)
			continue ;
		if (handle_heredocs(heredocs, ast) != 0)
			continue ;
		disable_raw_mode();
		exec_ast(ast);
		enable_raw_mode();
		ast_destroy(ast);
	}
}
