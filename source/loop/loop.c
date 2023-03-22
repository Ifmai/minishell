/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:52:20 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/22 23:00:08 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

char	*remove_spaces(char	*str)
{
	while (str && *str != '\0' && *str == ' ')
		str++;
	return (str);
}

void	minishell_loop(void)
{
	t_bool	flag;

	g_data->path = NULL;
	while (1)
	{
		g_data->signals = 1;
		g_data->signal_select = DEFAULT;
		g_data->line = readline("uWuShell :3 ");
		if ((macrocomp(remove_spaces(g_data->line), "")))
			continue ;
		ctrl_d(g_data->line);
		add_history(g_data->line);
		divide_string(g_data->line, g_data->dvd_str);
		count_pipe_rec();
		flag = syntax_err();
		init_heredoc();
		g_data->in_fd = -2;
		g_data->out_fd = -2;
		g_data->i = 0;
		g_data->_redirection->redir_control = 1;
		if (g_data->dvd_str->pipe_count == 0 && flag != TRUE \
			&& g_data->signals == 1)
			exec_one_command();
		else if (g_data->dvd_str->pipe_count > 0 && flag != TRUE \
			&& g_data->signals == 1)
			exec_multiple_command();
		else if (g_data->signals == 1)
			printf("erorr pü\n"); // bu error değişicek
		reset_command_struct(flag);
		system("leaks minishell");
	}
}

//env de old path güncellencek güncellemedik aq.