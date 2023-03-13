/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:57:48 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 21:14:25 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

char	*add_symbol()
{
	char	*cwd;
	char	*added;
	char	buff[4096 + 1];

	cwd = getcwd(buff, 4096);
	added = ft_strjoin(cwd, "/");
	return (added);
}

int	set_std_file(int in_fd, int out_fd)
{
	int	ret;

	ret = 0;
	if (in_fd >= 0) 
	{
		if (dup2(in_fd, STDIN_FILENO) == -1) 
			ret = -1;
	}

	if (out_fd >= 0) 
	{
		if (dup2(out_fd, STDOUT_FILENO) == -1)
			ret = -1;
	}
	return (ret);
}

void	assign_in_out(char *edited_param, char *symbol, char *redir_param)
{
	if (!ft_strncmp("<", symbol, 1))
	{
		if (data->in_fd >= 0)
			close(data->in_fd);
		if (macrocomp("<<", symbol))
			data->in_fd = open("includes/.heredoc.txt", O_RDONLY, 0777);
		else
			data->in_fd = open(edited_param, O_RDONLY, 0777);
		if (data->in_fd < 0)
		{
			printf("%s: No such file or directory\n", redir_param);
			exit(1);
		}
	}
	else
	{
		if (data->out_fd >= 0)
			close(data->out_fd);
		if (macrocomp(">>", symbol))
			data->out_fd = open(edited_param, O_WRONLY \
			| O_CREAT | O_APPEND, 0777);
		else
			data->out_fd = open(edited_param, O_WRONLY \
			| O_CREAT | O_TRUNC, 0777);
		if (data->out_fd < 0)
			exit(1);
	}
}

void	file_operations(char *redir_param, char *symbol, t_redirection *redir) {
	char	*edited_param;
	(void)redir;

	if (redir_param[0] == '/')
		edited_param = redir_param;
	else
		edited_param = ft_strjoin(add_symbol(), redir_param);
	assign_in_out(edited_param, symbol, redir_param);

	if (set_std_file(data->in_fd, data->out_fd) == -1)
	{
		exit(1);
	}
	free(edited_param);
}



char    **change_command(char **command, int i)
{
    char    **new_command;
    int     j;
    int     index;

    j = 0;
    index = 0;
    new_command = ft_calloc(sizeof(char *) , chardb_len(command) - 1);
    while(command[j])
    {
        if(j == i)
            j += 2;
        else
        {
            new_command[index] = command[j];
            index++;
            j++;
        }
    }
    return (new_command);
}

char    **redirection(char **command)
{
    int     index;
    int     i;

    i = 0;
    index = 0;
    while(command[i] != 0 && command[i+1])
    {
        if(is_redir_symbol_string(command[i]))
        {
            file_operations(command[i + 1] , command[i], data->_redirection);
            command = change_command(command, i);
        }
        else
            i++;
    }
    return (command);
}

