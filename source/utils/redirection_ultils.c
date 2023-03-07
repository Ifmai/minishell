/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_ultils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:05:01 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/28 14:09:38 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*data;

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
		counter_redirection(iter->str, data->_redirection, -1);
		iter = iter->next;
	}
	redirection_value_define(data->_redirection);
	data->pid = malloc(sizeof(pid_t) * 1);
	data->fd = malloc(sizeof(data->fd) * data->dvd_str->pipe_count);
}

void    counter_redirection(char *str, t_redirection *redirection , int i)
{
    while(str[++i] != 0)
    {
        if(str[i] == '\"' && redirection->temp_quote == 0)
            redirection->temp_db_quote++;
        else if(str[i] == '\'' && redirection->temp_db_quote == 0)
            redirection->temp_quote++;
        if(str[i] == '<' && _macro("NOQT"))
        {
            if(str[i + 1] == '<')
            {
                redirection->heredoc++;
                i++;
            }
            else
                redirection->input++;
        }
        if(str[i] == '>' && _macro("NOQT"))
        {
            if(str[i + 1] == '>')
            {
                redirection->appened++;
                i++;
            }
            else
                redirection->output++;
        }
        if(_macro("QTorFT"))
            _macro("reset_quoete");
    }
}

/* void    define_value(t_lexer *lexer)
{
    t_redirection   *iter;
	int				i;

	i = 0;
    iter = lexer;
    while (!iter = NULL)
    {
        if(macrocomp(iter->str, "<<"))
		{
			data->_redirection->heredoc_string[]
		}
    }
}
 */
void    redirection_value_define(t_redirection *rec)
{
	/* t_lexer	*iter;

	iter = data->dvd_str->lexer; */
    rec->heredoc_string = ft_calloc(rec->heredoc, sizeof(char *));
    rec->input_string = ft_calloc(rec->input, sizeof(char *));
    rec->appened_string = ft_calloc(rec->appened, sizeof(char *));
    rec->output_string = ft_calloc(rec->output, sizeof(char *));
/* 	while(iter != NULL)
	{
		while()
    	define_value(iter, "<<");

	} */
}