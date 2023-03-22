/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:52:20 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/21 23:07:06 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

char	*remove_spaces(char	*str)
{
	//int	len;

	while (*str == ' ')
		str++;
	//len = ft_strlen(str);
	//while (len > 0 && str[len - 1] == ' ')
	//{
	//	str[len - 1] = '\0';
	//	len--;
	//}
	return (str);
}

void	minishell_loop(void)
{
	t_bool	flag;

	while (1)
	{
		ft_signal();
		g_data->line = readline("uWuShell >");
		if ((macrocomp(remove_spaces(g_data->line), "")))
			continue ;
		ctrl_d(g_data->line);
		add_history(g_data->line);
		divide_string(g_data->line, g_data->dvd_str);
		count_pipe_rec();
		flag = syntax_err();
		init_heredoc();
		//delete_qoute();
		g_data->in_fd = -1;
		g_data->out_fd = -1;
		g_data->i = 0;
		if (g_data->dvd_str->pipe_count == 0 && flag != TRUE)
			exec_one_command();
		else if (g_data->dvd_str->pipe_count > 0 && flag != TRUE)
			exec_multiple_command();
		reset_command_struct();
		//system("leaks minishell");
	}
}

//env de old path güncellencek güncellemedik aq.