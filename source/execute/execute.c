/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 03:33:28 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/23 20:59:23 by hozdemir         ###   ########.fr       */
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
		if(access(true_path, F_OK) != -1 )
		{
			printf("burdan döndüm true \n");
			return (true_path);
		}
		free(true_path);
		i++;
	}
	free(true_path);
	return (true_path);
}

void    exec_one_command()
{
	char	**command;
	char	*true_path;
	
	//froklıyıp access kullanıp command create kullancaz onu yapcan bropa
	data->pid[0] = fork();
	if(data->pid[0] == 0)
	{
		command = command_create();
		true_path = true_command(command);
		printf("%s\n",true_path);
		if(true_path)
			execve("/bin/ls", command, data->env);
		else
		{
			printf("hatalı komut kanka %s",command[0]);
			exit (0);
		}
	}
	else
		while (waitpid(-1,0,0) != -1);
}
