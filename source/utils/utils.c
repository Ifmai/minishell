/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:27:45 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/12 23:10:14 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

void	define_struct(void)
{
	data->dvd_str = malloc(sizeof(t_divide_str));
	data->dvd_str->lexer = NULL;
	data->_redirection = malloc(sizeof(t_redirection));
 	_macro("VALUE_RESET");
}

int	chardb_len(char **db)
{
	int	i;

	i = 0;
	while(db[i] != 0)
		i++;
	return (i);	
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		if (s1[i] < s2[i] || s1[i] > s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

int	len_list(t_lexer *lst)
{
	t_lexer	*iter;
	int		i;

	iter = lst;
	i = 0;
	while (iter != NULL)
	{
		if(iter->str[0] == '|')
			break;
		i++;
		iter = iter->next;
	}
	return (i);
}

int	check_trim(char a, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (a == set[i])
			return (1);
		i++;
	}
	return (0);
}
