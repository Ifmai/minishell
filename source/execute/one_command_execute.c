/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_command_execute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 03:33:28 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/10 20:04:57 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

void    exec_one_command()
{
	int		builtins;
	char	**command;
	char	**exec_command;
	char	*true_path;

	true_path = NULL;
	command = command_create();
	builtins = is_it_builtins(command);
	if(builtins == FALSE)
		true_path = true_command(command);
	if(true_path || builtins == TRUE)
	{
		data->pid[0] = fork();
		//lexer için edit_data yapcaz çünkü siktiğimin $ işaretini değiştirmiyoruz normalde vb. burçakcım halleder xd.
		if(data->pid[0] == 0)
		{
			exec_command = redirection(command);
			if(builtins == FALSE)
				execve(true_path, exec_command, data->env);
			execute_builtins(exec_command[0], exec_command);
			exit(0);
		}
		else
			while (waitpid(-1,0,0) != -1);
		free(true_path);
	}
	else if(chardb_len(command) != 0)
		printf("bash: command not found: %s\n",command[0]);
	free_command_db(command);
}
