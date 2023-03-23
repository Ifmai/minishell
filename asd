CFLAGS = -Wall -Werror -Wextra -I./lib/readline/include -g #-fsanitize=address 
all: $(LIB) $(LIBFT_DIR) $(LIBFT) ${NAME} 
re: fclean all
.PHONY: all bonus fclean re 
