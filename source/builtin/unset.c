/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:28:33 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/21 18:47:51 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

int	get_index(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

void	delete_env(const char *varname)
{
	int		index;
	int		env_len;
	char	**new_env;
	int		j;
	int		i;

	j = 0;
	i = 0;
	env_len = chardb_len(g_data->env);
	new_env = (char **)malloc(sizeof(char *) * (env_len + 1));
	if (new_env == NULL)
	{
		printf("Error: Memory allocation failed.\n");
		return ;
	}
	while (i < env_len)
	{
		index = get_index(g_data->env[i]);
		if (ft_strncmp(g_data->env[i], varname, index) != 0)
			new_env[j++] = ft_strdup(g_data->env[i]);
		i++;
	}
	new_env[j] = NULL;
	free_command_db(g_data->env);
	g_data->env = new_env;
}

void	delete_export(const char *varname)
{
	int		index;
	int		export_len;
	char	**new_export;
	int		j;
	int		i;

	j = 0;
	i = 0;
	export_len = chardb_len(g_data->export);
	new_export = (char **)malloc(sizeof(char *) * (export_len + 1));
	if (new_export == NULL)
	{
		printf("Error: Memory allocation failed.\n");
		return ;
	}
	while (i < export_len)
	{
		index = get_index(g_data->export[i]);
		if (ft_strncmp(g_data->export[i], varname, index) != 0)
			new_export[j++] = ft_strdup(g_data->export[i]);
		i++;
	}
	new_export[j] = NULL;
	free_command_db(g_data->export);
	g_data->export = new_export;
}

void	unset_command(char **args)
{
	int		i;

	i = 0;
	if (args[1] == NULL)
	{
		printf("unset: Too few arguments.\n");
		return ;
	}
	while (args[i] != NULL)
	{
		delete_env(args[i]);
		delete_export(args[i]);
		i++;
	}
}
