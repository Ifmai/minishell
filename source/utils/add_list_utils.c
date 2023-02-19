/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:27:45 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/18 20:57:53 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

char	*add_str(t_divide_str *dvd, char *str, int *i)
{
	char	*divide;
	int		index;

	index = (*i);
	i_plus(str, i);
	while(str[*i] != 0)
	{
		if(checker_red_pipe(str[*i - 1], str[*i], dvd))
			break;
		check_in_str(str[*i], dvd);
		if(((str[*i] == 32 && _macro("NOQ")) || \
			(_macro("RTORF") && _macro("NOQ"))))
			break ;
		(*i)++;
	}
	if(_macro("RTORF"))
		reset_redirection(dvd);
	divide = ft_substr(str, index, (*i) - index);
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
		if((lst))
			new->back = last_item(*lst);
		(last_item(*lst))->next = new;
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
	node->back = NULL;
	node->next = NULL;
	return (node);
}

/* char	*add_que(t_divide_str *dvd, char *str, int *i)
{
	char	*divide;
	int		index;

	if(QTorF(dvd->db_quote, dvd->quote))
		(*i)++;
	index = (*i);
	while(str[*i] != 0)
	{
		check_in_str(str[*i], dvd);
		if(dvd->quote == 2 || dvd->db_quote == 2)
			break ;
		(*i)++;
	}
	divide = ft_substr(str, index, (*i) - index);
	return (divide);
} */
