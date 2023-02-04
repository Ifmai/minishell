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


//Macro Define
//# define CheckStr(c) ((((c >= 97 && c <= 122) || (c <= 90 && c >= 65)) || (c <= 57 && c >= 48)) ? 1 : 0)
# define QTorF(x, z) ((x == 1 || z == 1) ? 1 : 0)
# define STR(c, x) (((c != 32 && (c == 0 || x == 32))) ? 1 : 0)

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
	char			*line;
	char			**env;
	int				check_signal;
	t_divide_str	*dvd_str;
}				t_data;

// include main function
void	minishell_loop(void);
void	divide_string(char *str, t_divide_str *dvd_str);


//Utils
void	define_struct(void);
char	**ft_env(char **env);
int		chardb_len(char **db);
void	get_signal(int incoming);

// Add list function
void	add(t_lexer **lst, t_lexer *new);
t_lexer	*last_item(t_lexer *lst);
t_lexer	*new_node(void *content);
char	*add_str(t_divide_str *dvd, char *str, int *i);
void	check_in_str(char str, t_divide_str *dvd);

#endif
