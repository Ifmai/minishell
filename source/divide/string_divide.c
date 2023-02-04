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

static void	reset_quoete(t_divide_str *dvd)
{
	dvd->quote = 0;
	dvd->db_quote = 0;
}

void	check_in_str(char str, t_divide_str *dvd)
{
	if(str == '\"' && dvd->quote == 0)
		dvd->db_quote++;
	else if(str == '\'' && dvd->db_quote == 0)
		dvd->quote++;
	if(str == '|' && NoQ(dvd->db_quote, dvd->quote))
		dvd->pipe_count++;
}

void	divide_string(char *str, t_divide_str *dvd)
{
	int	i;

	i = 0;
	while(str[i])
	{
		check_in_str(str[i], data->dvd_str);
		if(QTorF(dvd->db_quote, dvd->quote))
		{
			i++;
			add(&dvd->lexer, new_node(add_que(dvd, str, &i)));
			reset_quoete(dvd);
			i++;
		}
		else if(STR(str[i]))
		{
			add(&dvd->lexer, new_node(add_str(dvd, str, &i)));
			i++;
		}
		else
			i++;
	}
}