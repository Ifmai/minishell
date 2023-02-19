/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:27:45 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/19 15:12:49 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

void	reset_quoete(t_divide_str *dvd)
{
	dvd->quote = 0;
	dvd->db_quote = 0;
}

void	create_path()
{
	int		i;
	char	*temporary;

	i = 0;
	while(data->env[i][0] != 'P')
		i++;
	temporary = ft_strdup(data->env[i]);
	i = 0;
	while(temporary[i] != '/')
		i++;
	data->path = ft_split((temporary + i) , ':');
	free(temporary);
}

void	define_struct(void)
{
	data->dvd_str = malloc(sizeof(t_divide_str));
	data->dvd_str->lexer = NULL;
	data->dvd_str->db_quote = 0;
	data->dvd_str->quote = 0;
	data->dvd_str->pipe_count = 0;
	data->dvd_str->rec_db_l = 0;
	data->dvd_str->rec_db_r = 0;
	data->dvd_str->rec_l = 0;
	data->dvd_str->rec_r = 0;
	data->check_signal = 0;
}

int	chardb_len(char **db)
{
	int	i;

	i = 0;
	while(db[i])
		i++;
	return (i);	
}

int	len_list(t_lexer *lst)
{
	t_lexer	*iter;
	int		i;

	iter = lst;
	i = 0;
	while (iter != NULL)
	{
		if(iter->str[0] == '|' || iter->str[0] == '<' ||
			iter->str[0] == '>')
				break;
		i++;
		iter = iter->next;
	}
	return (i);
}
