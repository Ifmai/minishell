/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_pipe_divide.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:02:07 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/21 18:02:34 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

void	reset_redirection(t_divide_str *dvd)
{
	dvd->rec_l = 0;
	dvd->rec_r = 0;
	dvd->pipe_count = 0;
}

static int	check_rec(char one, char two)
{
	if (one == two)
		return (1);
	return (0);
}

int	checker_red_pipe(char one, char two)
{
	if (_macro("NOQ") && ((one == '<' || one == '>') || one == '|') && \
		(two == '\'' || two == '\"'))
		return (1);
	if (_macro("NOQ") && (one == '|') && (two == '|'))
		return (1);
	return (0);
}

void	i_plus(char *str, int *i)
{
	if ((str[*i] == '\'' || str[*i] == '\"'))
		(*i)++;
	if ((str[*i] == '<' || str[*i] == '>') && _macro("NOQ"))
	{
		if (check_rec(str[*i], str[*i + 1]))
			(*i) += 2;
		else
			(*i)++;
	}
	if (str[*i] == '|' && _macro("NOQ"))
		(*i)++;
}
