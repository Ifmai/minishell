/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:57:25 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 19:03:45 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

t_bool is_variable_char(char data)
{
    if(data >= 'A' && data <= 'Z')
        return true;
    else if (data >= 'a' && data <= 'z')
        return true;
    else if(data >= '0' && data <= '9')
        return true;
    else if(data == '_')
        return true;
    else
        return false;
}

int variable_len(char *data)
{
    int len = 0;
    if(data[len] == '?')
        return (1);
    while (data[len] != '\0' &&\
    is_variable_char(data[len]))
        len++;
    return len;
}

char    *get_variable(char *input)
{
	char	*var_data;
    char	*temp;
	int 	i;

	i = 0;
    if(*input == '$' && *(input+1) != '\0')
	{
		input++;
        if(*input == '?')
            return(ft_itoa(data->_var));
		i = variable_len(input);
		temp = ft_substr(input,0,i);
		var_data = get_env(temp);
		free(temp);
		if(var_data == NULL)
			var_data = ft_strdup("");
		return (var_data);
	}
	else
		return (ft_strdup("$"));
}