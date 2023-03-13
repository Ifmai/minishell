/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_divide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:55:33 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/28 12:59:32 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

void	check_in_str(char str, t_divide_str *dvd)
{
	if (str == '\"' && dvd->quote == 0)
		dvd->db_quote++;
	else if (str == '\'' && dvd->db_quote == 0)
		dvd->quote++;
	if (str == '|' && _macro("NOQ"))
		dvd->pipe_count++;
	if (str == '<' && _macro("NOQ") \
	&& _macro("NOR"))
		dvd->rec_l++;
	if (str == '>' && _macro("NOQ") \
	&& _macro("NOR"))
		dvd->rec_r++;
	if (_macro("QTorF"))
		_macro("reset_quoete");
}

void	divide_string(char *str, t_divide_str *dvd)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		check_in_str(str[i], data->dvd_str);
		if (str[i] != 32)
			add(&dvd->lexer, new_node(add_str(dvd, str, &i)));
		else
			i++;
	}
}
