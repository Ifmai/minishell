/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:21:22 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 17:31:24 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data  *data;

void	free_fd(void)
{
	int	i;

	i = 0;
	while (i < data->dvd_str->pipe_count)
	{
		free(data->fd[i]);
		i++;
	}
	free(data->fd);
}

void	close_pipe_fd(void)
{
	int	i;

	i = 0;
	while (i < data->dvd_str->pipe_count)
	{
		close(data->fd[i][0]);
		close(data->fd[i][1]);
		i++;
	}
}

void	create_pipe_fd(void)
{
	int	i;

	i = 0;
	while (i < data->dvd_str->pipe_count)
	{
		data->fd[i] = malloc(sizeof(int) * 2);
		pipe(data->fd[i]);
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
