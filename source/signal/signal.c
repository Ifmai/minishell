/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:40:18 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/22 16:25:12 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

void	ctrl_d(char *input)
{
	if (!input && g_data->signal_select != HEREDOC)
	{
		printf("exit\n");
		exit(0);
	}
	if(g_data->signal_select == HEREDOC)
	{
		g_data->_redirection->torf = TRUE;
		return ;
	}
}

void	ft_sig(int signo)
{
	(void)signo;
	if (g_data->signal_select == HEREDOC)
	{
		g_data->signals = 0;
		write(1, "\033[A", 3);
		ioctl(0, TIOCSTI, "\n");
	}
	else if (g_data->signal_select != CHILD)
	{
		g_data->signals = 0;
		write(1, "\033[A", 3);
		ioctl(0, TIOCSTI, "\n");
	}
	else
		printf("\n");
}

void	sigquit_handler(int sig)
{
	(void)sig;
	if (g_data->signal_select == CHILD)
		write(1, "Quit: 3\n", 8);
}


void	ft_signal(void)
{
	signal(SIGQUIT, sigquit_handler);
	signal(SIGINT, ft_sig);
}