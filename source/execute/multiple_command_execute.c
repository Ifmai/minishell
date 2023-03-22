/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_command_execute.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:13:38 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/22 23:04:28 by hozdemir         ###   ########.fr       */
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

void	execute_command(char *true_path, int builtins, char **command, int i)
{
	if (true_path || builtins == TRUE)
	{
		g_data->signal_select = CHILD;
		g_data->pid[0] = fork();
		if (g_data->pid[0] == CHILD)
		{
			select_dup2(i);
			set_std_file(g_data->in_fd, g_data->out_fd);
			if (builtins == TRUE)
				execute_builtinz(command[0], command, 0);
			execve(true_path, command, g_data->env);
			exit(1);
		}
		else
		{
			close_pipe(i);
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
	char	**new_command;

	i = 0;
	true_path = NULL;
	create_pipe_fd();
	while (i <= g_data->dvd_str->pipe_count)
	{
		g_data->i = i;
		command = command_create();
		command = redirection(command);
		new_command = edit_command(command);
		builtins = is_it_builtinz(new_command);
		if (builtins == FALSE)
			true_path = true_command(new_command);
		execute_command(true_path, builtins, new_command, i);
		free_command_db(new_command);
		i++;
	}
	while (waitpid(-1, &g_data->_var, 0) != -1)
		continue ;
	g_data->signal_select = DEFAULT;
}

