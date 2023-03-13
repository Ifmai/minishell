/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:52:20 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 19:20:39 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

void	minishell_loop(void)
{
	t_bool	flag;

	while (1)
	{
		data->line = readline("uWuShell >");
		if (macrocomp(data->line, ""))
			continue ;
		add_history(data->line);
		divide_string(data->line, data->dvd_str);
		count_pipe_rec();
		flag = syntax_err();
		init_heredoc();
		delete_qoute();
		data->in_fd = -1;
		data->out_fd = -1;
		if (data->dvd_str->pipe_count == 0 && ft_strlen(data->line) != 1 \
			&& flag != TRUE)
			exec_one_command();
		else if (data->dvd_str->pipe_count > 0 && flag != TRUE)
			exec_multiple_command();
		reset_command_struct();
	}
}
