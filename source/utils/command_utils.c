/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:58:54 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/19 09:05:45 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;


char	**command_create()
{
	static int	i = 0;
	int			len;
	t_lexer		*iter;
	char		**command;

	iter = data->dvd_str->lexer;
    len = -1;
    while(++len < i && iter != NULL)
        iter = iter->next;
	len = len_list(iter);
	command = ft_calloc(sizeof(char *) , len + 1);
    if(!command || !iter)
        return (0);
    len = 0;
	while(iter != NULL && !(iter->str[0] == '|' || iter->str[0] == '<' ||
			iter->str[0] == '>'))
	{
		command[len] = ft_strdup(iter->str);
        i++;
        len++;
        iter = iter->next;
	}
	if(iter != NULL && (iter->str[0] == '|' || iter->str[0] == '<' ||
			iter->str[0] == '>'))
				i++;
	return (command);
}