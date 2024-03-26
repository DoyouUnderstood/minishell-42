NAME = minishell
SRCS = $(shell find src -type f -name '*.c')
OBJS = $(SRCS:.c=.o)
LIBFT = libs/libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibs/libft
LDFLAGS = -Llibs/libft
LDLIBS = -lreadline -lft
SANITIZE_FLAGS = -g3 -fsanitize=address

.PHONY: all clean fclean re sanitize run valgrind-run test valgrind-test

all: $(NAME)

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

run: all
	./$(NAME)

valgrind-run: all
	valgrind -- ./$(NAME)

test: run fclean

valgrind-test: valgrind-run fclean

.SILENT: