/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_command_execute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 03:33:28 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/21 17:52:55 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

void	exec_one_command_1(char *true_path, int builtins, char **command)
{
	t_bool	redir;
	char	**exec_command;

	redir = is_redir_symbol_string(command[0]);
	if (true_path || builtins == TRUE || redir == TRUE)
	{
		g_data->pid[0] = fork();
		if (g_data->pid[0] == 0)
		{
			exec_command = redirection(command);
			if (builtins == FALSE)
				execve(true_path, exec_command, g_data->env);
			execute_builtins(exec_command[0], exec_command, 0);
			exit(1);
		}
		else
			while (waitpid(-1, &g_data->_var, 0) != -1)
				continue ;
		free(true_path);
	}
	else if (chardb_len(command) != 0)
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

	true_path = NULL;
	command = command_create();
	builtins = is_it_builtins(command);
	if (builtins == FALSE)
		true_path = true_command(command);
	exec_one_command_1(true_path, builtins, command);
	free_command_db(command);
}
