SRCS = ./source/main.c ./source/utils/utils.c ./source/utils/env_add.c ./source/loop/loop.c ./source/divide/string_divide.c \
		./source/utils/add_list_utils.c
NAME = minishell
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./lib/readline/include
RM = rm -rf
LIBC = ar -rcs
LIBFT = ./libft/libft.a
GET_NEXT_LINE = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
LIB				= ./lib/.minishell
LDFLAGS			= -L./lib/readline/lib -lreadline

all: $(LIB) $(LIBFT) ${NAME} 

$(NAME): $(SRCS) ${LIBFT}
	@gcc $(CFLAGS) $(LDFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "<3 :3 uWuShell :3 <3"

$(LIBFT):
	@make -C ./libft

$(LIB):
	@make -C ./lib


fclean:
	@${RM} $(NAME)


fffclean: fclean
	@make fclean -C ./lib

re: fclean all

.PHONY: all bonus fclean re 

