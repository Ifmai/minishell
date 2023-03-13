/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_ultils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:05:01 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 22:20:05 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

void	count_pipe_rec(void)
{
	int		i;
	t_lexer	*iter;

<<<<<<< Updated upstream
	reset_redirection(data->dvd_str);
	iter = data->dvd_str->lexer;
	while (iter != NULL)
=======
	reset_redirection(g_data->dvd_str);
	iter = g_data->dvd_str->lexer;
	while(iter != NULL)
>>>>>>> Stashed changes
	{
		i = 0;
		while (iter->str[i] != 0)
		{
			check_in_str(iter->str[i], g_data->dvd_str);
			i++;
		}
		iter = iter->next;
	}
	g_data->pid = malloc(sizeof(pid_t) * 1);
	g_data->fd = malloc(sizeof(g_data->fd) * g_data->dvd_str->pipe_count);
}

