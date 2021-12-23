NAME = push_swap
HEADER_FILES = push_swap.h test_source/test.h
SRC_FILES = source/error.c source/parse.c source/fill_stack.c source/print.c\
	source/find.c source/move.c source/sort.c source/sort_small.c\
	source/push.c source/swap.c source/rotate.c source/reverse_rotate.c
OBJ_FILES = $(SRC_FILES:.c=.o)
TEST = test
TEST_SRC_FILES = test_source/benchmark.c test_source/random.c
TEST_OBJ_FILES = $(TEST_SRC_FILES:.c=.o)
CC = gcc
C_FLAGS = -I. -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c $(HEADER_FILES) Makefile
	$(CC) $(C_FLAGS) -c $< -o $@

$(NAME): source/main.o $(OBJ_FILES) libft/libft.a
	$(CC) source/main.o $(OBJ_FILES) libft/libft.a -o $(NAME)

$(TEST): test_source/main.o $(TEST_OBJ_FILES) $(OBJ_FILES) libft/libft.a
	$(CC) test_source/main.o $(TEST_OBJ_FILES) $(OBJ_FILES) libft/libft.a -o $(TEST)

libft/libft.a:
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJ_FILES)
	rm -f $(TEST_OBJ_FILES)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)
	rm -f $(TEST)

re: fclean all

.PHONY: all norme clean fclean re
