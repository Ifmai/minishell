/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_command_execute.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:13:38 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/24 19:43:03 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data  *data;

void    execute_command(char *true_path, char **command, int i)
{
    data->pid[i] = fork();
    if(data->pid[i] == 0)
    {
        if(i == 0)
            dup2(data->fd[0], 1);
        else if(i > 0 && i < data->dvd_str->pipe_count)
            dup2(data->fd[1],0);
        else if(i == data->dvd_str->pipe_count)
            close_pipe_fd();
        execve(true_path, command, data->env);
        exit(0);
    }
    else
		while (waitpid(-1,0,0) != -1);
}

void    exec_multiple_command()
{
    int i;
    char    **command;
    char    *true_path;
    
    i = 0;
    pipe(data->fd);
    while(i <= data->dvd_str->pipe_count)
    {
        command = command_create();
        true_path = true_command(command);
        if(true_path)
            execute_command(true_path, command, i);
        else
            printf("bash: command not found: %s\n",command[0]);
        free_command_db(command);
        i++;
    }
}