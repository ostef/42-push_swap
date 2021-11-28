NAME = push_swap
HEADER_FILES = push_swap.h
SRC_FILES = source/main.c source/stack.c source/sort.c\
	source/swap.c\
	source/push.c\
	source/rotate.c\
	source/rev_rotate.c
OBJ_FILES = $(SRC_FILES:.c=.o)
CC = gcc
C_FLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

%.o: %.c $(HEADER_FILES)
	$(CC) $(C_FLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES) libft/libft.a
	$(CC) $(OBJ_FILES) libft/libft.a -o $(NAME)

libft/libft.a:
	make -C libft

norme:
	make -C libft norme
	@norminette $(SRC_FILES)
	@norminette $(HEADER_FILES)

clean:
	make -C libft clean
	rm -f $(OBJ_FILES)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all norme clean fclean re
