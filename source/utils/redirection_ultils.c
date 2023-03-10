/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_ultils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:05:01 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/28 14:09:38 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*data;

void	count_pipe_rec()
{
	int	i;
	t_lexer	*iter;

	reset_redirection(data->dvd_str);
	iter = data->dvd_str->lexer;
	while(iter != NULL)
	{
		i = 0;
		while(iter->str[i] != 0)
		{
			check_in_str(iter->str[i],data->dvd_str);
			i++;
		}
		iter = iter->next;
	}
	data->pid = malloc(sizeof(pid_t) * 1);
	data->fd = malloc(sizeof(data->fd) * data->dvd_str->pipe_count);
}

