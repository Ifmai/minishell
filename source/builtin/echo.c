/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:55:33 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 17:50:43 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

void	echo_command(char **command)
{
	int		i;
	char	*check;

	check = ft_strtrim(command[1], "-n");
	i = 1;
    if (!command[i])
    {
     printf("\n");
    return ;
    }
    if (check[0] == 0)
        i = 2;
    while (command[i])
    {
        write(1, command[i], ft_strlen(command[i]));
        if(command[i + 1] != 0)
            write(1, " ", 1);
        i++;    
    }
    if( !(check[0] == 0))
        printf("\n");
    free(check);
}