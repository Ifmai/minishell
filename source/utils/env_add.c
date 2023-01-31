/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 04:15:05 by hozdemir          #+#    #+#             */
/*   Updated: 2023/01/31 05:31:34 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

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