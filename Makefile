NAME = push_swap
HEADER_FILES = push_swap.h libft/libft.h
SRCS = source/error.c source/parse.c source/parse_args.c source/fill_stack.c source/print.c\
	source/find.c source/move.c source/sort.c source/sort_small.c\
	source/push.c source/swap.c source/rotate.c source/reverse_rotate.c
OBJS = $(SRCS:.c=.o)
PUSH_SWAP_SRCS = $(SRCS) source/main.c
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)
TEST = test
TEST_HEADERS = $(HEADER_FILES) test_source/test.h
TEST_SRCS = test_source/main.c test_source/benchmark.c test_source/random.c
TEST_OBJS = $(TEST_SRCS:.c=.o)
LIBFT = libft/libft.a
CC = gcc
C_FLAGS = -I. -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c $(HEADERS_FILES) Makefile
	$(CC) $(C_FLAGS) -c $< -o $@

$(TEST_OBJS): %.o: %.c $(TEST_HEADERS) Makefile
	$(CC) $(C_FLAGS) -c $< -o $@

$(NAME): $(PUSH_SWAP_OBJS) $(LIBFT)
	$(CC) $(PUSH_SWAP_OBJS) $(LIBFT) -o $(NAME)

$(TEST): $(TEST_OBJS) $(OBJS) $(LIBFT)
	$(CC) $(TEST_OBJS) $(OBJS) $(LIBFT) -o $(TEST)

$(LIBFT):
	make -C libft

clean:
	make -C libft clean
	rm -f $(PUSH_SWAP_OBJS)
	rm -f $(TEST_OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)
	rm -f $(TEST)

re: fclean all

.PHONY: all norme clean fclean re
