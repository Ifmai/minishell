/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_pipe_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:02:07 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/23 20:40:43 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

void	count_pipe_rec()
{
	data->dvd_str->rec_l = _counter_macro(data->dvd_str->lexer, '<');
	data->dvd_str->rec_r = _counter_macro(data->dvd_str->lexer, '>');
	data->dvd_str->pipe_count = _counter_macro(data->dvd_str->lexer, '|');
	if(data->dvd_str->pipe_count == 0)
		data->pid = malloc(sizeof(pid_t) * 1); // hiç pipe yoksa pid için 1 lik yer açıyorum.
}


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
	if( _macro("NOQ") && ((one == '<' || one == '>') || one == '|') && \
		(two == '\'' || two == '\"') && dvd)
		return (1);
	if( _macro("NOQ") && (one == '|') && (two == '|') && dvd)
		return (1);
	return (0);
}

void	i_plus(char *str, int *i)
{
	if((str[*i] == '\'' || str[*i] == '\"'))
		(*i)++;
	if((str[*i] == '<' || str[*i] == '>') &&  _macro("NOQ"))
	{
		if(check_rec(str[*i], str[*i + 1]))
			(*i) += 2;
		else
			(*i)++;
	}
	if(str[*i] == '|' &&  _macro("NOQ"))
		(*i)++;
}