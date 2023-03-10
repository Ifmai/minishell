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
	return (TRUE);
}
