/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:21:22 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/24 18:31:13 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data  *data;

char	*true_command(char **command)
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
			return (true_path);
		free(true_path);
		i++;
	}
	return (0);
}

void    close_pipe_fd()
{
    close(data->fd[0]);
    close(data->fd[1]);
}

void    free_command_db(char **command)
{
    int i;

    i = 0;
    while(command[i] != 0)
        free(command[i++]);
    free(command);
}