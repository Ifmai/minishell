/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:21:22 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/28 00:33:39 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data  *data;

void	execute_builtins(char *select, char **command)
{
	if(macrocomp(select, "echo"))
		echo_command(command);
	else if(macrocomp(select, "pwd"))
		pwd_command(command);
	/* else if(macrocomp(select, "export"))
		export_command(command); */
	/* else if(macrocomp(select, "exit"))
		return (TRUE);
	else if(macrocomp(select, "env"))
		return (TRUE); */
}

void    free_fd()
{
	int	i;

	i = 0;
	while(i < data->dvd_str->pipe_count)
	{
    	free(data->fd[i]);
		i++;
	}
	free(data->fd);
}

void    close_pipe_fd()
{
	int	i;

	i = 0;
	while(i < data->dvd_str->pipe_count)
	{
    	close(data->fd[i][0]);
    	close(data->fd[i][1]);
		i++;
	}
}

void	create_pipe_fd()
{
	int	i;

	i = 0;
    while(i < data->dvd_str->pipe_count)
    {
		data->fd[i] = malloc(sizeof(int) * 2);
        pipe(data->fd[i]);
        i++;
    }
}

void    free_command_db(char **command)
{
    int i;

    i = 0;
    while(command[i] != 0)
        free(command[i++]);
    free(command);
}