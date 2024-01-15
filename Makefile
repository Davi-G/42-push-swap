#------------MakeFile------------#
NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = ./src/
SRCS =	push_swap.c \
		push_swap_main.c \
		push_swap_utils.c \
		push_swap_rules_1.c \
		push_swap_rules_2.c \
		push_swap_sort_1.c \
		push_swap_sort_2.c \
		push_swap_parser.c \
		push_swap_check.c

OBJS_DIR = ./obj/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

all: obj lib $(NAME)

obj:
	mkdir obj

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -I ./includes/ -I ./42-libft/ -o $@ -c $< -g

lib: 
	make -C 42-libft/

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L ./42-libft/ -l ft -o $(NAME) -g

clean:
	rm -rf obj push_swap
	make clean -C 42-libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C 42-libft/

re: clean all

test_mov:
	./push_swap 4 3 2 1 | wc -l

test:
	./push_swap 2 65 3 457 8287 624 32

.PHONY: all clean fclean re
