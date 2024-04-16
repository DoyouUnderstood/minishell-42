NAME = minishell
SRCS = src/ast/ast.c src/ast/ast_2.c src/ast/ast_print.c src/directory/directory.c src/dyn_array/dyn_arr.c src/dyn_array/dyn_arr_2.c src/dyn_array/dyn_arr_3.c src/env/env.c src/env/env_2.c src/env/env_init.c src/exec/exec.c src/exec/exec_and_or.c src/exec/exec_builtin.c src/exec/exec_builtin_2.c src/exec/exec_builtin_3.c src/exec/exec_builtin_4.c src/exec/exec_cmd.c src/exec/exec_errors.c src/exec/exec_pipeline.c src/exec/exec_pipeline_function.c src/exec/exec_subshell.c src/exec/pid_list.c src/expansion/expand.c src/expansion/expand_params.c src/expansion/expand_params2.c src/expansion/expand_split_words.c src/expansion/expand_unquote.c src/expansion/expand_wildcard.c src/ft_error/ft_error.c src/ft_error/ft_error_2.c src/ft_error/ft_error_3.c src/ft_signal/ft_signal.c src/ft_signal/ft_signal2.c src/ft_sprintf/ft_sprintf.c src/ft_sprintf/ft_sprintf_fill.c src/ft_sprintf/ft_sprintf_len.c src/global/global.c src/hash_map/hash_map.c src/hash_map/hash_map_2.c src/hash_map/hash_map_3.c src/heredoc_list/heredoc_list.c src/heredoc_list/heredoc_list_2.c src/main.c src/parse/parse.c src/parse/parse_and_or.c src/parse/parse_full_cmd.c src/parse/parse_pipeline.c src/parse/tl_scanner.c src/parse/tl_scanner2.c src/path/path_build_list.c src/path/path_build_list_2.c src/path/path_find.c src/redir_list/redir_list.c src/redir_list/redir_list_2.c src/redir_list/redir_list_3.c src/scanner/scanner.c src/scanner/scanner_2.c src/scanner/scanner_3.c src/scanner/scanner_create.c src/string/string.c src/string/string_2.c src/string/string_3.c src/token/token.c src/token/token_op_value.c src/token_list/token_list.c src/token_list/token_list_2.c src/tokenize/tokenize.c src/tokenize/tokenize_2.c src/tokenize/tokenize_3.c src/wildcard/wildcard.c src/word_list/word_list.c src/word_list/word_list_2.c src/word_list/word_list_3.c src/ft_signal/raw_mode.c
OBJS = $(SRCS:.c=.o)
LIBFT = libs/libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibs/libft
LDFLAGS = -Llibs/libft
LDLIBS = -lreadline -lft
SANITIZE_FLAGS = -g3 -fsanitize=address

.PHONY: all bonus clean fclean re sanitize

all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(LIBFT):
	$(MAKE) -s --no-print-directory -C libs/libft

clean:
	$(MAKE) -s --no-print-directory -C libs/libft clean
	rm -f $(OBJS)

fclean:
	$(MAKE) -s --no-print-directory -C libs/libft fclean
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all

sanitize: CFLAGS += $(SANITIZE_FLAGS)
sanitize: fclean $(NAME)