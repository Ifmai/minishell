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

#define Qt(hold,num) ((hold+num) % (num*2))

// Structs
typedef struct s_lexer
{
	char			*str;
	//int				error; fonksiyonu durdurmak için kullanabiliriz.
	struct s_lexer	*next;
	struct s_lexer	*back;
}					t_lexer;

typedef struct s_red
{
	int		fd_appened;
	int		fd_input;
	int		fd_output;// fazlalık. rec fonksiyonları için en azından 
	int		fd_heredoc;// fazlalık. heredoc da kullandın mı bilmiyom ama rec fonksiyonlarıda gereksiz buda.
}			t_redirection;

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
	char			**export;
	int				check_signal;
	char			**path;
	pid_t			*pid;
	t_divide_str	*dvd_str;
	t_redirection	*_redirection;
	int				**fd;
	int				command_count;
	int				in_fd;
	int				out_fd;
}				t_data;

// include main function
void	minishell_loop(void);
void	divide_string(char *str, t_divide_str *dvd_str);


//Utils
void	define_struct(void);
char	**ft_env(char **env);
void    export_create();
int		chardb_len(char **db);
void	check_in_str(char str, t_divide_str *dvd);
int		check_trim(char a, char const *set);
int		ft_strcmp(char *s1, char *s2);
char	**double_strdup(char **s1);

//Buildin function
void    echo_command();
void    pwd_command(char **command);
void    cd_command(char **command);
void    export_command(char **command);

//Export Utils funciton
char    *free_new_strdup(char *_free, char *command);
char    *new_strdup(char *command);
char    **double_strjoin(char **s1, char *add);

// Add list function
void	add(t_lexer **lst, t_lexer *new);
t_lexer	*last_item(t_lexer *lst);
t_lexer	*new_node(void *content);
//char	*add_que(t_divide_str *dvd, char *str, int *i);

//Parse utils
char	*add_str(t_divide_str *dvd, char *str, int *i);
void	i_plus(char *str, int *i);
int		checker_red_pipe(char one, char two);
void	create_path();

//reset utils
void	reset_redirection(t_divide_str *dvd);
void	reset_command_struct();
void    free_command_db(char **command);
void    free_fd();

//Execute function
void    exec_one_command();
void    exec_multiple_command();
void    close_pipe_fd();
void	create_pipe_fd();
void	execute_builtins(char *select, char **command);

//Edit Data
char* add_char(char* str, char add_char);
char *edit_data(char *substring);

//Command utils
char	**command_create();
void    counter_redirection(char *str, t_redirection *redirection , int i);
void	delete_qoute();
int		len_list(t_lexer *lst);
int		_counter_macro(t_lexer *lexer, char search);
void	count_pipe_rec();
char	*new_str_join(char  *s1, char  *s2);
char	*true_command(char **command);
char	*new_strtrim(char *s1, char *set);
int		is_it_builtins(char **command);

//Variables
char    *get_variable(char *input);
t_bool	is_variable_char(char data);
int		variable_len(char *data);

//Quote utils
void	reset_q_type(int q_hold);
int		quote_type(char quote,int *q_hold);
t_bool	is_contains_quote(char *input);

//Rec utils function
t_bool is_redir_symbol(t_lexer *lexer);
t_bool is_redir_symbol_string(char *lexer);
t_bool syntax_err();
void	init_heredoc(void);
void	read_heredoc(char *limiter,t_redirection *redir);
void 	wait_limiter(char *limiter,int fd);
char    **redirection(char **comand);
//void	redirection(t_data *data);
void	remove_node(t_lexer **head, t_lexer *node);
void	file_operations(char *redir_param,char *symbol, t_redirection *redir);
char	*add_symbol();
#endif
