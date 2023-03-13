/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:37:51 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 21:15:49 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

char	*get_env(char *find)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	while (data->env[i])
	{
	j = 0;
		while (data->env[i][j] && data->env[i][j] != '=')
			j++;
		flag = ft_strncmp(data->env[i], find, j);
		if (flag == 0)
			break ;
		i++;
	}
	return (ft_substr(data->env[i], j + 1, ft_strlen(data->env[i]) - j));
}

void	add_env(char *command)
{
	int	i;
	int	j;
	int	flag;

	j = 0;
	flag = 0;
	i = 0;
	while (command[j] && command[j] != '=')
		j++;
	while (data->env[i])
	{
		flag = ft_strncmp(data->env[i], command, j);
		if (flag == 0)
			break ;
		i++;
	}
	if (flag == 0)
		data->env[i] = free_new_strdup(data->env[i], command, 0);
	else
		data->env = double_strjoin(data->env, ft_strdup(command));
}

void	write_env(void)
{
	int	i;

	i = 0;
	while (data->env[i])
		printf("%s\n", data->env[i++]);
}

void	env_command(char **command, int flag)
{
	int	i;

	i = 1;
	if (command[i] == 0 && flag == 0)
		write_env();
}
