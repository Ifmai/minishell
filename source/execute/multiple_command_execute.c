/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_command_execute.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:13:38 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 21:04:21 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data  *data;

void	select_dup2(int i)
{
	if (i == 0)
	{
		dup2(data->fd[i][1], 1);
		close(data->fd[i][1]);
	}
	else if (i > 0 && i < data->dvd_str->pipe_count)
	{
		dup2(data->fd[i - 1][0], 0);
		dup2(data->fd[i][1], 1);
		close(data->fd[i - 1][0]);
		close(data->fd[i][1]);
		close(data->fd[i - 1][1]);
	}
	else if (i == data->dvd_str->pipe_count)
	{
		dup2(data->fd[i - 1][0], 0);
		close_pipe_fd();
	}
	close_pipe_fd();
}

void	execute_command(char *true_path, int builtins, char **command, int i)
{
	char	**exec_command;

	if (true_path || builtins == TRUE)
	{
		data->pid[0] = fork();
		if (data->pid[0] == 0)
		{
			select_dup2(i);
			exec_command = redirection(command);
			if (builtins == FALSE)
				execve(true_path, exec_command, data->env);
			execute_builtins(exec_command[0], exec_command, 0);
			exit(0);
		}
		else
		{
			if (i == data->dvd_str->pipe_count)
				close_pipe_fd();
			else if (i > 0 && i < data->dvd_str->pipe_count)
			{
				close(data->fd[i - 1][0]);
				close(data->fd[i - 1][1]);
			}
			free(true_path);
		}
	}
	else if (chardb_len(command) != 0)
	{
		printf("bash: command not found: %s\n", command[0]);
		data->_var = 127;
	}
}

void	exec_multiple_command(void)
{
	int		i;
	int		builtins;
	char	**command;
	char	*true_path;

	i = 0;
	true_path = NULL;
	create_pipe_fd();
	while (i <= data->dvd_str->pipe_count)
	{
		command = command_create();
		builtins = is_it_builtins(command);
		if (builtins == FALSE)
			true_path = true_command(command);
		execute_command(true_path, builtins, command, i);
		free_command_db(command);
		i++;
	}
	while (waitpid(-1, &data->_var, 0) != -1);
}
