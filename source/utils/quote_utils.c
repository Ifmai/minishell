/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:13:54 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/23 00:22:18 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

t_bool	is_contains_quote(char *input)
{
	while (*input)
	{
		if (*input == '\'' || *input == '\"')
			return (TRUE);
		input++;
	}
	return (FALSE);
}

int	quote_type(char quote, int *q_hold)
{
	static int	hold = 0;

	if (quote == '\'' || quote == '\"')
	{
		if (quote == '\'' && (hold == 0 || hold == 1))
		{
			*q_hold = qt(*q_hold, 1);
			if (hold == 0)
				hold = 1;
			else if (hold == 1)
				hold = 0;
			return (1);
		}
		else if (quote == '\"' && (hold == 0 || hold == 2))
		{
			*q_hold = qt(*q_hold, 2);
			if (hold == 0)
				hold = (2);
			else if (hold == 2)
				hold = 0;
			return (2);
		}
	}
	return (0);
}

void	reset_q_type(int q_hold)
{
	if (q_hold == 0)
		return ;
	else if (q_hold == 1)
		quote_type('\'', &q_hold);
	else
		quote_type('\"', &q_hold);
}

int	qt(int hold, int num)
{
	return ((hold + num) % (num * 2));
}
