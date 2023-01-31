/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_divide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:55:33 by hozdemir          #+#    #+#             */
/*   Updated: 2023/01/31 09:47:15 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

static void	check_in_str(char str, t_divide_str *dvd_str, int i)
{
	if(str == '\"' && dvd_str->quote == 0)
	{
		dvd_str->db_quote++;
		dvd_str->cut_line_start = i;
	}
	else if(str== '\'' && dvd_str->db_quote == 0)
	{
		dvd_str->quote++;
		dvd_str->cut_line_start = i;
	}
	if(str == '|' && dvd_str->db_quote == 0
		&& dvd_str->quote == 0)
		dvd_str->pipe_count++;
	if(dvd_str->db_quote == 2)
	{
		dvd_str->db_quote = 0;
		dvd_str->cut_line_end = i;
	}
	if(dvd_str->quote == 2)
	{
		dvd_str->quote = 0;
		dvd_str->cut_line_end = i;
	}
}

void	divide_string(char *str, t_divide_str *dvd_str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		
	}
}