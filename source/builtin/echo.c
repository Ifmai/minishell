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

void    echo_command(char **command)
{
    int fd;
    int i;

    i = 1;
    fd = 1;
    if(macrocomp(command[1], "-n"))
        i = 2;
    if(command[i] == 0)
        return ;
    if(data->_redirection->output || data->_redirection->appened)
        fd = data->_redirection->fd_rec;// output varsa bunu kullancaz.
    while(command[i])
    {
        write(fd,command[i],ft_strlen(command[i]));
        if(command[i + 1] != 0)
            write(1," ",1);
        i++;
    }
    if(!macrocomp(command[1], "-n"))
        printf("\n");
}