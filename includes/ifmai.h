/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifmai.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:42:36 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 21:33:09 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <sys/ioctl.h>
# include "../libft/libft.h"

# define QT(hold, num) ((hold + num) % (num * 2))

// Structs
typedef struct s_lexer
{
	char			*str;
	struct s_lexer	*next;
	struct s_lexer	*back;
}					t_lexer;

typedef struct s_red
{
	int		fd_appened;
	int		fd_input;
	int		fd_output;
	int		fd_heredoc;
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
	int				_var;
}				t_data;

// include main function
void	minishell_loop(void);
void	divide_string(char *str, t_divide_str *dvd_str);
void	ft_signal(void);

//Utils
void	define_struct(void);
char	**ft_env(char **env);
void	export_create(void);
int		chardb_len(char **db);
void	check_in_str(char str, t_divide_str *dvd);
int		check_trim(char a, char const *set);
int		ft_strcmp(char *s1, char *s2);
char	**double_strdup(char **s1);
char	*add_symbol(void);
t_bool	syntax_err(void);
char	*get_env(char *find);
void	ctrl_d(char *input);

// Divide_string utils
char	*add_str(t_divide_str *dvd, char *str, int *i);
void	i_plus(char *str, int *i);
int		checker_red_pipe(char one, char two);
void	create_path(void);

// Divide_string : Add list function
void	add(t_lexer **lst, t_lexer *new);
t_lexer	*last_item(t_lexer *lst);
t_lexer	*new_node(void *content);

// Divide_string : Edit Data
char	*add_char(char	*str, char add_char);
char	*edit_data(char	*substring, t_bool var_flag, t_bool q_flag);

// Divide_string : Variables
char	*get_variable(char *input);
t_bool	is_variable_char(char data);
int		variable_len(char *data);

// Divide_string : Variables : Quote utils
void	reset_q_type(int q_hold);
int		quote_type(char quote, int *q_hold);
t_bool	is_contains_quote(char *input);

// Loop : reset utils
void	reset_redirection(t_divide_str *dvd);
void	reset_command_struct(void);
void	free_command_db(char **command);
void	free_fd(void);

//Buildin function
void	echo_command(char **command);
void	pwd_command(char **command);
void	cd_command(char **command);
void	export_command(char **command, int flag);
void	env_command(char **command, int flag);
void	exit_command(char **command);

//Buildin : Env Utils funciton 
void	write_env(void);
void	add_env(char *command);

//Buildin : Export Utils funciton
char	*free_new_strdup(char *_free, char *command, int flag);
char	*new_strdup(char *command);
char	**double_strjoin(char **s1, char *add);

//Execute function
void	exec_one_command(void);
void	exec_multiple_command(void);
void	close_pipe_fd(void);
void	create_pipe_fd(void);
void	execute_builtins(char *select, char **command, int flag);

//Execute : Command utils
char	**command_create(void);
void	counter_redirection(char *str, t_redirection *redirection, int i);
void	delete_qoute(void);
int		len_list(t_lexer *lst);
int		_counter_macro(t_lexer *lexer, char search);
void	count_pipe_rec(void);
char	*new_str_join(char	*s1, char	*s2);
char	*true_command(char **command);
char	*new_strtrim(char *s1, char *set);
int		is_it_builtins(char **command);

// Redirection function
char	**redirection(char **comand);
void	init_heredoc(void);
void	read_heredoc(char *limiter);
void	wait_limiter(char	*limiter, int fd);

// Redirection : Heredoc Utils
void	remove_node(t_lexer **head, t_lexer *node);
void	file_operations(char	*redir_param, \
char	*symbol, t_redirection	*redir);
t_bool	is_redir_symbol(t_lexer *lexer);
t_bool	is_redir_symbol_string(char *lexer);

void	assign_in_out(char *edited_param, char *symbol, char *redir_param);
int		set_std_file(int in_fd, int out_fd);

#endif
