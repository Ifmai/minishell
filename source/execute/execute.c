/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 03:33:28 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/23 19:37:13 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

static char	*true_command(char **command)
{
	int		i;
	char	*true_path;

	i = 0;
	while (data->path[i] != 0)
	{
		true_path = ft_strdup(data->path[i]);
		true_path = new_str_join(true_path, "/");
		true_path = new_str_join(true_path, command[0]);
		if(accsess(true_path))
			break;
		free(true_path);
		i++;
	}
	true_path = ft_strdup(data->path[i]);
	return (i);
}

void    exec_one_command()
{
	int		i;
	char	**command;
	char	*true_path;
	
	//froklıyıp access kullanıp command create kullancaz onu yapcan bropa
	data->pid[0] = fork();
	if(data->pid[0] == 0)
	{
		command = command_create();
		true_path = true_command(command);
		execve(true_path,command,data->env);
		exit (0);
	}
	else
		waitpid(data->pid[0]);
}
