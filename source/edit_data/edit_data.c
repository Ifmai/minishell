/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:58:28 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/21 16:46:41 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

char	*char_to_str(char ch)
{
	char	*str;

	str = malloc(2 * sizeof(char));
	str[0] = ch;
	str[1] = '\0';
	return (str);
}

char	*edit_data(char	*substring, t_bool var_flag, t_bool q_flag)
{
	char	*edited_data;
	char	*joined_data;
	int		quote;

	quote = 0;
	joined_data = ft_strdup("");
	while (*substring != '\0')
	{
		while (q_flag && quote_type(*substring, &quote))
			substring++;
		if (*substring != '\0')
		{
			if (var_flag && quote != 1 && *substring == '$')
			{
				edited_data = get_variable(substring++);
				substring += variable_len(substring);
			}
			else
				edited_data = char_to_str(*substring++);
			joined_data = new_str_join(joined_data, edited_data);
			free(edited_data);
		}
	}
	reset_q_type(quote);
	return (joined_data);
}

char	*add_char(char	*str, char add_char)
{
	int		str_len;
	char	*new_str;

	str_len = ft_strlen(str);
	new_str = ft_calloc(str_len + 3, 1);
	new_str[0] = add_char;
	ft_memcpy(new_str + 1, str, str_len);
	new_str[str_len + 1] = add_char;
	free(str);
	return (new_str);
}

char	**double_strdup(char **s1)
{
	char	**rtn;
	int		len;
	int		i;

	i = 0;
	len = chardb_len(s1) + 1;
	rtn = ft_calloc(len, sizeof(char *));
	if (!rtn)
		return (0);
	while (s1[i] != 0)
	{
		rtn[i] = s1[i];
		i++;
	}
	free(s1);
	return (rtn);
}
