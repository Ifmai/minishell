/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:21:22 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 22:21:34 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data 	*g_data;

void	free_fd(void)
{
	int	i;

	i = 0;
	while (i < g_data->dvd_str->pipe_count)
	{
    	free(g_data->fd[i]);
		i++;
	}
	free(g_data->fd);
}

void	close_pipe_fd(void)
{
	int	i;

	i = 0;
	while (i < g_data->dvd_str->pipe_count)
	{
    	close(g_data->fd[i][0]);
    	close(g_data->fd[i][1]);
		i++;
	}
}

void	create_pipe_fd(void)
{
	int	i;

	i = 0;
    while (i < g_data->dvd_str->pipe_count)
    {
		g_data->fd[i] = malloc(sizeof(int) * 2);
        pipe(g_data->fd[i]);
        i++;
    }
}

void	free_command_db(char **command)
{
	int	i;

    i = 0;
	while (command[i] != 0)
		free(command[i++]);
	free(command);
}
