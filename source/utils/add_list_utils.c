/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:27:45 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 22:17:43 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

char	*add_str(t_divide_str *dvd, char *str, int *i)
{
	char	*divide;
	int		index;

	index = (*i);
	i_plus(str, i);
	while (str[*i] != 0)
	{
		if ((*i) != 0 && checker_red_pipe(str[*i - 1], str[*i]))
			break ;
		check_in_str(str[*i], dvd);
		if (((str[*i] == 32 && _macro("NOQ")) || \
			(_macro("RTORF") && _macro("NOQ"))))
			break ;
		(*i)++;
	}
	if (_macro("RTORF"))
		reset_redirection(dvd);
	divide = ft_substr(str, index, (*i) - index);
	return (divide);
}

char	*new_strtrim(char *s1, char *set)
{
	size_t	len;
	size_t	i;
	char	*rtn;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1) - 1;
	while (check_trim(s1[i], set))
		i++;
	while (check_trim(s1[len], set))
		len--;
	rtn = ft_substr(s1, i, len - i + 1);
	if (!rtn)
		return (NULL);
	free(s1);
	return (rtn);
}

void	add(t_lexer **lst, t_lexer *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
		(*lst) = new;
	else
	{
		if ((lst))
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
