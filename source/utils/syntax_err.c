/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:14:18 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/23 03:27:14 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

int	int_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s && *s != 0)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

t_bool	is_redir_symbol(t_lexer *lexer)
{
	if (macrocomp(lexer->str, "<") || macrocomp(lexer->str, ">"))
		return (TRUE);
	return (FALSE);
}

t_bool	is_redir_symbol_string(char *lexer)
{
	if (!lexer)
		return (FALSE);
	if (!ft_strncmp(lexer, "<", 1) || !ft_strncmp(lexer, ">", 1))
	{
		return (TRUE);
	}
	return (FALSE);
}

t_bool	pipe_syntax(t_lexer	*lexer)
{
	if (macrocomp(lexer->str, "|"))
	{
		if (!lexer->next || macrocomp(lexer->next->str, "|"))
		{
			lexer->next = NULL;
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	syntax_err(void)
{
	t_lexer	*lexer;

	lexer = g_data->dvd_str->lexer;
	while (lexer)
	{
		if (pipe_syntax(lexer))
			return (TRUE);
		if (is_redir_symbol_string(lexer->str))
		{
			if (!(lexer->next) || is_redir_symbol(lexer->next) \
				|| macrocomp(lexer->next->str, "|"))
			{
				lexer->next = NULL;
				return (TRUE);
			}
		}
		lexer = lexer->next;
	}
	return (FALSE);
}
