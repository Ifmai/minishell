/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_divide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:21:25 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/21 17:54:50 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

t_bool	nor(void)
{
	if (g_data->dvd_str->rec_l == 0 && g_data->dvd_str->rec_r == 0)
		return (TRUE);
	return (FALSE);
}

t_bool	rtorf(void)
{
	if ((g_data->dvd_str->rec_l == 1 || g_data->dvd_str->rec_r == 1) || \
		g_data->dvd_str->pipe_count == 1)
		return (TRUE);
	return (FALSE);
}

t_bool	qtorf(void)
{
	if (g_data->dvd_str->db_quote == 2 || g_data->dvd_str->quote == 2)
		return (TRUE);
	return (FALSE);
}

t_bool	noq(void)
{
	if (g_data->dvd_str->db_quote == 0 && g_data->dvd_str->quote == 0)
		return (TRUE);
	return (FALSE);
}
