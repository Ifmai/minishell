/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:37:51 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 22:35:44 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

char	*get_env(char *find)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	while (g_data->env[i])
	{
		j = 0;
		while (g_data->env[i][j] && g_data->env[i][j] != '=')
			j++;
		flag = ft_strncmp(g_data->env[i], find, j);
		if (flag == 0)
			break ;
		i++;
	}
	if (flag != 0)
			return (NULL);
	return (ft_substr(g_data->env[i], j + 1, ft_strlen(g_data->env[i]) - j));
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
	while (g_data->env[i])
	{
		flag = ft_strncmp(g_data->env[i], command, j);
		if (flag == 0)
			break ;
		i++;
	}
	if (flag == 0)
		g_data->env[i] = free_new_strdup(g_data->env[i], command, 0);
	else
		g_data->env = double_strjoin(g_data->env, ft_strdup(command));
}

void	write_env(void)
{
	int	i;

	i = 0;
	while (g_data->env[i])
		printf("%s\n", g_data->env[i++]);
}

void	env_command(char **command, int flag)
{
	int	i;

	i = 1;
	if (command[i] == 0 && flag == 0)
		write_env();
}
