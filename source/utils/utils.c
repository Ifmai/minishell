/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:27:45 by hozdemir          #+#    #+#             */
/*   Updated: 2023/01/31 09:37:44 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

void	define_struct(void)
{
	data->dvd_str = malloc(sizeof(t_divide_str));
	data->dvd_str->db_quote = 0;
	data->dvd_str->quote = 0;
	data->dvd_str->pipe_count = 0;
	data->dvd_str->rec_db_l = 0;
	data->dvd_str->rec_db_r = 0;
	data->dvd_str->rec_l = 0;
	data->dvd_str->rec_r = 0;
	data->check_signal = 0;
}

int	chardb_len(char **db)
{
	int	i;

	i = 0;
	while(db[i])
		i++;
	return (i);	
}

void get_signal(int incoming)
{
	if(incoming == 2)
		data->check_signal = 2;
}