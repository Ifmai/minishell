#ifndef IFMAI_H
# define IFMAI_H

// İnclude Header
# include "macro.h"
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
	struct s_lexer	*back;
}					t_lexer;


typedef struct s_divide_string
{
	int		db_quote;
	int		quote;
	int		pipe_count;
	int		rec_db_l;
	int		rec_db_r;
	int		rec_l;
	int		rec_r;
	t_lexer	*lexer;
}			t_divide_str;

typedef struct s_data
{
	char			*line;
	char			**env;
	int				check_signal;
	char			**path;
	t_divide_str	*dvd_str;
}				t_data;

// include main function
void	minishell_loop(void);
void	divide_string(char *str, t_divide_str *dvd_str);


//Utils
void	define_struct(void);
char	**ft_env(char **env);
int		chardb_len(char **db);
void	check_in_str(char str, t_divide_str *dvd);


// Add list function
void	add(t_lexer **lst, t_lexer *new);
t_lexer	*last_item(t_lexer *lst);
t_lexer	*new_node(void *content);
//char	*add_que(t_divide_str *dvd, char *str, int *i);

//Parse utils
char	*add_str(t_divide_str *dvd, char *str, int *i);
void	i_plus(char *str, int *i);
int		checker_red_pipe(char one, char two, t_divide_str *dvd);

//reset utils
void	reset_quoete(t_divide_str *dvd);
void	reset_redirection(t_divide_str *dvd);

//Path create function
void	create_path();

//Command utils
char	**command_create();
int	len_list(t_lexer *lst);

#endif
