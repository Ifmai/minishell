/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:52:20 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/19 15:14:06 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

void	minishell_loop(void)
{
	while(1)
	{
		//data_clear(data->dvd_str); Buraya bir clear yazılcak sonraki komutu düzgün alamıyor arkadaş bagli listeye.
		data->line = readline("uWuShell > ");
		if(data->line[0] == '.')
			break ;
		add_history(data->line);
		divide_string(data->line, data->dvd_str);
		count_pipe_rec();
/* 		if(data->dvd_str->pipe_count == 0)
			exec_one_command(); */
		/* else
			exec_multiple_command(); */
	}
}

// execve( path alıyor , command_create(dönen double array), env)

// Command Create Deneme kodu.