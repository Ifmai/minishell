/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_counter_redirection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:21:25 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/28 13:02:58 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

t_bool	reset_quoete()
{
	data->dvd_str->quote = 0;
	data->dvd_str->db_quote = 0;
	data->_redirection->temp_db_quote = 0;
	data->_redirection->temp_quote = 0;
	return (TRUE);
}

t_bool rtorft()
{
    if((data->_redirection->appened == 1 || data->_redirection->heredoc == 1 \
        || data->_redirection->input == 1 || data->_redirection->output == 1))
		return (TRUE);
	return (FALSE);
}

t_bool qtorft()
{
    if(data->_redirection->temp_db_quote == 2 \
        || data->_redirection->temp_quote == 2)
		return (TRUE);
	return (FALSE);
}

t_bool noqt()
{
     if(data->_redirection->temp_db_quote == 0 \
        && data->_redirection->temp_quote == 0)
		return (TRUE);
	return (FALSE);
}