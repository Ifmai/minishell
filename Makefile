SRCS = ./source/main.c ./source/utils/utils.c ./source/utils/env_add.c ./source/loop/loop.c ./source/divide/string_divide.c \
		./source/utils/add_list_utils.c ./source/utils/rec_pipe_divide.c ./source/macro/macro.c ./source/macro/macro_divide.c \
		./source/utils/command_utils.c ./source/execute/one_command_execute.c ./source/execute/multiple_command_execute.c \
		./source/utils/execute_utils.c ./source/utils/reset_utils.c ./source/macro/macro_counter_redirection.c \
		./source/utils/redirection_ultils.c ./source/builtin/echo.c ./source/builtin/cd_pwd.c ./source/builtin/export.c \
		./source/utils/export_utils.c ./source/edit_data/edit_data.c ./source/variables/variables.c ./source/utils/syntax_err.c \
		./source/utils/quote_utils.c ./source/redirection/redirection.c ./source/redirection/heredoc.c
NAME = minishell
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./lib/readline/include -fsanitize=address -g
RM = rm -rf
LIBC = ar -rcs
LIBFT = ./libft/libft.a
GET_NEXT_LINE = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
LIB				= ./lib/.minishell
LDFLAGS			= -L./lib/readline/lib -lreadline

all: $(LIB) $(LIBFT) ${NAME} 

$(NAME): $(SRCS) ${LIBFT}
	@gcc $(CFLAGS) $(LDFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "❤️ 💋 uWuShell 💋 ❤️"

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

