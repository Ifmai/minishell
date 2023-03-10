/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 03:33:28 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/10 19:47:21 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

void add_export(char *command)
{
    int i;
    int j;
    int flag;

    j = 0;
    flag = 0;
    i = 0;
    while(command[j] && command[j] != '=')
        j++;
    while(data->export[i])
    {
        flag = ft_strncmp(data->export[i], command, j);
        //printf("Giden export: %s, Dönen Flag: %d\n", data->export[i], flag);
        if(flag == 0)
            break ;
        i++;
    }
    if(flag == 0)
        data->export[i] = free_new_strdup(data->export[i], command);
    else
        data->export = double_strjoin(data->export, new_strdup(command));
}

static  void    write_export()
{
    int i;

    i = 0;
    while(data->export[i])
        printf("declare -x %s\n",data->export[i++]);
}

void    export_command(char **command)
{
    int i;

    i = 1;
    if(command[i] == 0)
        write_export();
    else
    {
        while(command[i])
        {   if(command[i][0] == '=' || ft_isdigit(command[i][0]) \
                || ft_strchr(command[i], 32))
                    printf("bash: export: `%s': not a valid identifier\n", command[i]);
            else
                add_export(command[i]);
            i++;
        }
    }
}

