/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_command_execute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 03:33:28 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/24 18:27:34 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

void    exec_one_command()
{
	char	**command;
	char	*true_path;
	
	//froklıyıp access kullanıp command create kullancaz onu yapcan bropa
	command = command_create();
	true_path = true_command(command);
	if(true_path)
	{
		data->pid[0] = fork();
		if(data->pid[0] == 0)
		{
			execve(true_path, command, data->env);
			exit(0);
		}
		else
			while (waitpid(-1,0,0) != -1);
	}
	else
		printf("bash: command not found: %s\n",command[0]);
    free_command_db(command);
}
