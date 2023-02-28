/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_pipe_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:02:07 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/28 00:35:17 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

void	count_pipe_rec()
{
	int	i;
	t_lexer	*iter;

	reset_redirection(data->dvd_str);
	iter = data->dvd_str->lexer;
	while(iter != NULL)
	{
		i = 0;
		while(iter->str[i] != 0)
		{
			check_in_str(iter->str[i],data->dvd_str);
			i++;
		}
		iter = iter->next;
	}
	data->pid = malloc(sizeof(pid_t) * 1);
	data->fd = malloc(sizeof(data->fd) * data->dvd_str->pipe_count);
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