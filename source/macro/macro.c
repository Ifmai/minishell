/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 04:49:27 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/23 20:17:46 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

int _macro(char *str)
{
    if(macrocomp(str, "NOQ"))
        return (noq());
	if(macrocomp(str, "QTorF"))
		return (qtorf());
	if(macrocomp(str, "NOR"))
		return (nor());
	if(macrocomp(str, "RTORF"))
		return (rtorf());
	return (FALSE);
}

int _counter_macro(t_lexer *lexer, char search)
{
	t_lexer	*iter;
	int		i;
	int		count;

	count = 0;
	iter = lexer;
	while(iter != NULL)
	{
		i = -1;
		while(iter ->str[++i])
		{
			if(iter->str[i] == search)
				count++;
		}
		iter = iter->next;
	}
	return (count);
}

t_bool macrocomp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != 0 || s2[i] != 0))
	{
		if (s1[i] != s2[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
