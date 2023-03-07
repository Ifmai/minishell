/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:52:20 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/28 14:05:55 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

void	minishell_loop(void)
{
	while(1)
	{
		data->line = readline("uWuShell > ");
		add_history(data->line);
		divide_string(data->line, data->dvd_str);
		/// syntax error kontrol fonksiyonu buraya yazılcak.
		count_pipe_rec();
		delete_qoute();
		if(data->dvd_str->pipe_count == 0 && ft_strlen(data->line) != 1)
			exec_one_command();
		else if(data->dvd_str->pipe_count > 0)
			exec_multiple_command();
		reset_command_struct();
		//system("leaks minishell");
	}
}
