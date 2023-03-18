/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_command_execute.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:13:38 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 22:13:48 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

void	select_dup2(int i)
{
	if (i == 0)
	{
		dup2(g_data->fd[i][1], 1);
		close(g_data->fd[i][1]);
	}
	else if (i > 0 && i < g_data->dvd_str->pipe_count)
	{
		dup2(g_data->fd[i - 1][0], 0);
		dup2(g_data->fd[i][1], 1);
		close(g_data->fd[i - 1][0]);
		close(g_data->fd[i][1]);
		close(g_data->fd[i - 1][1]);
	}
	else if (i == g_data->dvd_str->pipe_count)
	{
		dup2(g_data->fd[i - 1][0], 0);
		close_pipe_fd();
	}
	close_pipe_fd();
}

void	close_pipe(int i)
{
	if (i == g_data->dvd_str->pipe_count)
		close_pipe_fd();
	else if (i > 0 && i < g_data->dvd_str->pipe_count)
	{
		close(g_data->fd[i - 1][0]);
		close(g_data->fd[i - 1][1]);
	}
}

void	execute_command(char *true_path, int builtins, char **command, int i)
{
	char	**exec_command;

	if (true_path || builtins == TRUE)
	{
		g_data->pid[0] = fork();
		if (g_data->pid[0] == 0)
		{
			select_dup2(i);
			exec_command = redirection(command);
			if (builtins == FALSE)
				execve(true_path, exec_command, g_data->env);
			execute_builtins(exec_command[0], exec_command, 0);
			exit(1);
		}
		else
		{
			close_pipe(i);//?
			free(true_path);
		}
	}
	else if (chardb_len(command) != 0)
	{
		printf("bash: command not found: %s\n", command[0]);
		g_data->_var = 127;
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
	while (i <= g_data->dvd_str->pipe_count)
	{
		command = command_create();
		builtins = is_it_builtins(command);
		if (builtins == FALSE)
			true_path = true_command(command);
		execute_command(true_path, builtins, command, i);
		free_command_db(command);
		i++;
	}
	while (waitpid(-1, &g_data->_var, 0) != -1)
		continue ;
}
