/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:55:33 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 17:13:34 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

static char	*in_array(char *command, char *ret, int i)
{
	char	*first;
	char	*two;

	if (ft_strchr(command, '='))
	{
		while (command[i] != '=')
            i++;
		first = ft_substr(command, 0 , i + 1);
		two = ft_substr(command, i + 1, ft_strlen(command) - (i + 1));
		two = add_char(two, '\"');
		ret = ft_strjoin(first, two);
	}
	else
		ret = ft_strdup(command);
	return (ret);
}

char	*new_strdup(char *command)
{
	int		len;
	char	*new;

	if (ft_strchr(command, '='))
		len = ft_strlen(command) + 3;
	else
		len = ft_strlen(command) + 1;
	new = ft_calloc(sizeof(char), len);
	return (in_array(command, new, 0));
}

char	*free_new_strdup(char *_free, char *command, int flag)
{
	int		len;
	char	*new;

	if (ft_strchr(command, '='))
		len = ft_strlen(command) + 3;
	else
		len = ft_strlen(command) + 1;
	new = ft_calloc(sizeof(char), len);
	if (flag == 1)
		new = in_array(command, new, 0);
	else if (flag == 0)
		new = ft_strdup(command);
	free(_free);
	return (new);
}

char	**double_strjoin(char **s1, char *add)
{
	char	**ret;
	int		i;

	i = 0;
	ret = ft_calloc(sizeof(char *), chardb_len(s1) + 2);
	while (s1[i] != 0)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = add;
	free(s1);
	return (ret);
}
