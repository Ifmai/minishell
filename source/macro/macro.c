/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 04:49:27 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/28 00:34:07 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

int _macro(char *str)
{
    if(macrocomp(str, "NOQ"))
        return (noq());
	if(macrocomp(str, "QTorF"))
		return (qtorf());
	if(macrocomp(str, "NOR"))
		return (nor());
	if(macrocomp(str, "RTORF"))
		return (rtorf());
	if(macrocomp(str, "VALUE_RESET"))
		return (reset_value());
	return (FALSE);
}

int _counter_macro(t_lexer *lexer, char search)
{
	t_lexer	*iter;
	int		i;
	int		count;

	count = 0;
	iter = lexer;
	while(iter != NULL)
	{
		i = -1;
		while(iter ->str[++i])
		{
			if(iter->str[i] == search)
				count++;
		}
		iter = iter->next;
	}
	return (count);
}

t_bool macrocomp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != 0 || s2[i] != 0))
	{
		if (s1[i] != s2[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	reset_value()
{
	data->dvd_str->db_quote = 0;
	data->dvd_str->quote = 0;
	data->dvd_str->pipe_count = 0;
	data->dvd_str->rec_db_l = 0;
	data->dvd_str->rec_db_r = 0;
	data->dvd_str->rec_l = 0;
	data->dvd_str->rec_r = 0;
	data->check_signal = 0;
	return (TRUE);
}