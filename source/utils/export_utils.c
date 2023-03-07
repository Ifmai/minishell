/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_divide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:55:33 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/28 12:59:32 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

char    *in_array(char *command, char *ret, int j, int i)
{
    int flag;
    char    *first;

    flag = ft_strchr(command, "=");
    if(flag != 0)
    {
        while(command[i] != '=')
            i++;
        first = ft_substr(command, 0 , i + 1);
        
        
    }

}
/*     while(j < len)
        {
            if(command[i] != 0)
            {
                new[j] = command[i];
                i++;
            }
            if((command[i - 1] == '=') || (j > i && j + 2 == len))
            {
                if(j + 2 != len)
                    j++;
                new[j] = '\"';
            }
            j++;
        }  */

char    *new_strdup(char *command)
{
    int i;
    int len;
    int j;
    char    *new;

    i = 0;
    j = 0;
    if(ft_strchr(command, '='))
        len = ft_strlen(command) + 3;
    else
        len = ft_strlen(command) + 1;
    new = ft_calloc(sizeof(char), len);
    while(command[i] != 0 | command[i] == '=')
        i++;
    return (new);
}

char    *free_new_strdup(char *_free, char *command)
{
    int i;
    int len;
    int j;
    char    *new;

    i = 0;
    j = 0;
    if(ft_strchr(command, '='))
        len = ft_strlen(command) + 3;// çift tırnak ve null için toplam 3
    else
        len = ft_strlen(command) + 1;
    new = ft_calloc(sizeof(char), len);
    while(i < len)
    {
        new[j] = command[i];
        if((command[i] == '=') || (j > i && j + 1 == len))
        {
            j++;
            new[j] = '\"';
        }
        i++;
        j++;
    }
    free(_free);
    return (new);
}

char    **double_strjoin(char **s1, char *add)
{
    char    **ret;
    int     i;

    i = 0;
    ret = ft_calloc(sizeof(char *), chardb_len(s1) + 2);
    while(s1[i] != 0)
    {
        ret[i] = s1[i];
        i++;
    }
    ret[i] = add;
    free(s1);
    return (ret);
}

