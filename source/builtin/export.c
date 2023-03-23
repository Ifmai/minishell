/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 03:33:28 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/23 03:32:30 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

void	add_export(char *command)
{
	int		i;
	int		j;
	int		flag;
	char	*join_array;

	j = 0;
	flag = 0;
	i = -1;
	while (command[j] && command[j] != '=')
		j++;
	while (g_data->export[++i])
	{
		flag = ft_strncmp(g_data->export[i], command, j);
		if (flag == 0)
			break ;
	}
	if (flag == 0)
		g_data->export[i] = free_new_strdup(g_data->export[i], command, 1);
	else
	{
		join_array = new_strdup(command);
		g_data->export = double_strjoin(g_data->export, join_array);
	}
}

static	void	write_export(void)
{
	int	i;

	i = 0;
	while (g_data->export[i])
		printf("declare -x %s\n", g_data->export[i++]);
}

void	export_command(char **command, int flag)
{
	int	i;

	i = 1;
	if (command[i] == 0 && flag == 0)
		write_export();
	else
	{
		while (command[i])
		{
			if (command[i][0] == '=' || ft_isdigit(command[i][0]) \
				|| int_strchr(command[i], 32))
			{
				printf("bash: export: '%s': not a \
					valid identifier\n", command[i]);
				i++;
				continue ;
			}
			else
				add_export(command[i]);
			if (int_strchr(command[i], '='))
				add_env(command[i]);
			i++;
		}
	}
}
