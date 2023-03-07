/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_command_execute.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:13:38 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/28 00:38:46 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data  *data;

void    select_dup2(int i)
{
    if(i == 0)
    {
        dup2(data->fd[i][1], 1);
        close(data->fd[i][1]);
    }
    else if(i > 0 && i < data->dvd_str->pipe_count)
    {
        dup2(data->fd[i - 1][0], 0);
        dup2(data->fd[i][1], 1);
        close(data->fd[i - 1][0]);
        close(data->fd[i][1]);
        close(data->fd[i - 1][1]);
    }
    else if(i == data->dvd_str->pipe_count)
    {
        dup2(data->fd[i - 1][0], 0);
        close_pipe_fd();
    }
    close_pipe_fd();
}

void    execute_command(char *true_path, char **command, int i)
{
    data->pid[0] = fork();
    if(data->pid[0] == 0)
    {
        select_dup2(i);
        execve(true_path, command, data->env);
        exit(0);
    }
    else
    {
        if(i == data->dvd_str->pipe_count)
            close_pipe_fd();
        else if(i > 0 && i < data->dvd_str->pipe_count) {
            close(data->fd[i - 1][0]);
            close(data->fd[i - 1][1]);
        }
        free(true_path);
    }
}

void     exec_multiple_command()
{
    int i;
    char    **command;
    char    *true_path;

    i = 0;
    create_pipe_fd();
    while(i <= data->dvd_str->pipe_count)
    {
        command = command_create();
        true_path = true_command(command);
        if(true_path)
            execute_command(true_path, command, i);
        else if (chardb_len(command) != 0)
            printf("bash: command not found: %s\n",command[0]);
        free_command_db(command);
        i++;
    }
    while (waitpid(-1,0,0) != -1);
	//free_fd();
}