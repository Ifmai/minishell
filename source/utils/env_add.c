/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 04:15:05 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/28 03:36:54 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*data;

char **ft_env(char **env)
{
	int	i;
	char **result;

	i = 0;
	while(env[i])
		i++;
	result = ft_calloc(sizeof(char **) , chardb_len(env) + 1);
	i = -1;
	while(env[++i])
		result[i] = ft_strdup(env[i]);
	return (result);
}

void	create_path()
{
	int		i;
	char	*temporary;

	i = 0;
	while(data->env[i][0] != 'P')
		i++;
	temporary = ft_strdup(data->env[i]);
	i = 0;
	while(temporary[i] != '/')
		i++;
	data->path = ft_split((temporary + i) , ':');
	free(temporary);
}