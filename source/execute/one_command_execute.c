/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_command_execute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 03:33:28 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/21 23:56:04 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

void	exec_one_command_1(char *true_path, int builtins, char **command)
{
	t_bool	redir;
	redir = is_redir_symbol_string(command[0]);
	if (true_path || builtins == TRUE || redir == TRUE)
	{
		g_data->pid[0] = fork();
		if (g_data->pid[0] == 0)
		{
			if (set_std_file(g_data->in_fd, g_data->out_fd) == -1)
				exit(1);
			if (builtins == TRUE)
				execute_builtins(command[0], command, 0);
			execve(true_path, command, g_data->env);
			exit(1);
		}
		else
		{
			while (waitpid(-1, &g_data->_var, 0) != -1)
				continue ;
		}
		free(true_path);
	}
	else
	{
		printf("bash: command not found: %s\n", command[0]);
		g_data->_var = 127;
	}
}

void	exec_one_command(void)
{
	int		builtins;
	char	**command;
	char	*true_path;
	char	**new_command;

	true_path = NULL;
	command = command_create();
	command = redirection(command);
	new_command = edit_command(command);
	builtins = is_it_builtins(new_command);
	if (builtins == FALSE)
		true_path = true_command(new_command);
	exec_one_command_1(true_path, builtins, new_command);
	free_command_db(new_command);
}
