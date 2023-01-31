#ifndef IFMAI_H
# define IFMAI_H

// İnclude Header
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <signal.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"


// Structs

typedef struct s_lexer
{
	char			*str;
	struct s_lexer	*next;
}					t_lexer;


typedef struct s_divide_string
{
	int		db_quote;
	int		quote;
	int		pipe_count;
	int		cut_line_start;
	int		cut_line_end;
	t_lexer	*lexer;
}			t_divide_str;

typedef struct s_data
{
	char			*line; // 8 
	char			**env;//8
	int				check_signal;//4 
	s_divide_str	*dvd_str;
}				t_data;

// include main function
void	minishell_loop(void);
void	divide_string(char *str, s_divide_str *dvd_str);


//Utils
void	define_struct(void);
char	**ft_env(char **env);
int		chardb_len(char **db);
void	get_signal(int incoming);

#endif
