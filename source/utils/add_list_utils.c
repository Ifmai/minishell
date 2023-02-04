/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:27:45 by hozdemir          #+#    #+#             */
/*   Updated: 2023/01/31 09:37:44 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

char	*add_que(t_divide_str *dvd, char *str, int *i)
{
	char	*divide;
	int		index;

	index = (*i) + 1;
	while(dvd->quote != 2 && dvd->db_quote != 2)
	{
		index++;
		check_in_str(str[index], dvd); 
	}
	if(QCheck(str[*i]))
		divide = ft_substr(str, *i + 1, index - (*i) - 1);
	else
		divide = ft_substr(str, *i, index - (*i));
	*i = index;
	return (divide);
}

char	*add_str(t_divide_str *dvd, char *str, int *i)
{
	char	*divide;
	int		index;

	index = (*i);
	while(str[index] != 32 && NoQ(dvd->db_quote, dvd->quote) && str[*i])
	{
		index++;
		check_in_str(str[index], dvd);
	}
	divide = ft_substr(str, *i, index - (*i));
	*i = index;
	return (divide);
}

void	add(t_lexer **lst, t_lexer *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
		(*lst) = new;
	else
	{
		(last_item(*lst))->next = new;
		(last_item(*lst))->next = NULL;
	}
}

t_lexer	*last_item(t_lexer *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_lexer	*new_node(void *content)
{
	t_lexer	*node;

	node = malloc(sizeof(t_lexer));
	if (!node)
		return (0);
	node->str = content;
	node->next = NULL;
	return (node);
}