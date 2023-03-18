/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:28:33 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 22:46:54 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

int get_index(const char *str)
{
    int i = 0;
    while (str[i] && str[i] != '=') {
        i++;
    }
    return i;
}

void delete_env(const char *varname)
{
    int index;
    int env_len;
    char **new_env;
    int j = 0;
    int i = 0;

    env_len = chardb_len(g_data->env);
    new_env = (char **)malloc(sizeof(char *) * (env_len + 1));
    if (new_env == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    while (i < env_len)
    {
        index = get_index(g_data->env[i]);
        if (ft_strncmp(g_data->env[i], varname, index) != 0)
            new_env[j++] = g_data->env[i];
        i++;
    }
    new_env[j] = NULL;
    g_data->env = new_env;
}

void unset_command(char **args)
{
    if (args[1] == NULL) {
        printf("unset: Too few arguments.\n");
        return;
    }
    for (int i = 1; args[i] != NULL; i++) {
        delete_env(args[i]);
    }
}
