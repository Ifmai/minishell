/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_pipe_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:02:07 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/16 03:36:20 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

void	reset_redirection(t_divide_str *dvd)
{
	dvd->rec_l = 0;
	dvd->rec_r = 0;
	dvd->pipe_count = 0;
}

static int	check_rec(char one, char two)
{
	if(one == two)
		return (1);
	else if (one == '>' && two == '<')
	{
		printf("syntax error near unexpected token `<'\n");
		exit(0);
	}
	return (0);
}

int	checker_red_pipe(char one, char two, t_divide_str *dvd)
{
	if(NoQ(dvd->db_quote, dvd->quote) && ((one == '<' || one == '>') || one == '|') && \
		(two == '\'' || two == '\"') && dvd)
			return (1);
	return (0);
}

void	i_plus(char *str, int *i, t_divide_str *dvd)
{
	if((str[*i] == '\'' || str[*i] == '\"'))
		(*i)++;
	if((str[*i] == '<' || str[*i] == '>') && NoQ(dvd->db_quote, dvd->quote))
	{
		if(check_rec(str[*i], str[*i + 1]))
			(*i) += 2;
		else
			(*i)++;
	}
	if(str[*i] == '|' && NoQ(dvd->db_quote, dvd->quote))
		(*i)++;
}