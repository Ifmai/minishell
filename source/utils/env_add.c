/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 04:15:05 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 18:15:42 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*data;

char	**ft_env(char **env)
{
	int		i;
	char	**result;

	i = 0;
	while (env[i])
		i++;
	result = ft_calloc(sizeof(char **), chardb_len(env) + 1);
	i = -1;
	while (env[++i])
		result[i] = ft_strdup(env[i]);
	return (result);
}

void	create_path(void)
{
	int		i;
	char	*temporary;

	i = 0;
	while (data->env[i][0] != 'P')
		i++;
	temporary = ft_strdup(data->env[i]);
	i = 0;
	while (temporary[i] && temporary[i] != '/')
		i++;
	data->path = ft_split((temporary + i), ':');
	free(temporary);
}

static void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	export_create(void)
{
	int		j;
	int		i;
	int		len;

	len = chardb_len(data->env);
	data->export = ft_env(data->env);
	i = 0;
	while (i < len - 1)
	{
		j = 1;
		while (j <  len - 1)
		{
			if (ft_strcmp(data->export[j], data->export[j + 1]) > 0)
				ft_swap(&data->export[j], &data->export[j + 1]);
			j++;
		}
		i++;
	}
}