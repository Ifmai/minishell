/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:14:18 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 22:24:02 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data  *g_data;

t_bool	is_redir_symbol(t_lexer *lexer)
{
	if (macrocomp(lexer->str, "<") || macrocomp(lexer->str, ">"))
		return (TRUE);
	return (FALSE);
}

t_bool	is_redir_symbol_string(char *lexer)
{
	if (!ft_strncmp(lexer, "<", 1) || !ft_strncmp(lexer, ">", 1))
	{
		return (TRUE);
	}
	return (FALSE);
}

t_bool	syntax_err(void)
{
	t_lexer	*head;
	t_lexer	*lexer;

	lexer = g_data->dvd_str->lexer;
	head = lexer;
	while (lexer && lexer->str)
	{
		if (macrocomp(lexer->str, "<") || macrocomp(lexer->str, ">"))
		{
			if (!(lexer->next) || is_redir_symbol(lexer->next) || macrocomp(lexer->str, "|"))
			{
				lexer->next = NULL;
				lexer = head;
				return (TRUE);
			}
		}
		lexer = lexer->next;
	}
	lexer = head;
	return (FALSE);
}