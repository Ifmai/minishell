/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:19:43 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/22 10:54:58 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

void	ctrl_d(char *input)
{
	if (!input)
	{
		printf("exit\n");
		exit(0);
	}
}

void	ft_sig(int signo)
{
	(void)signo;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	write(1, "\033[A", 3);
}

void	ft_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_sig);
}