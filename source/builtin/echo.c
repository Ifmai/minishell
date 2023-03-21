/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:55:33 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/21 16:29:38 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

static int	check_flag(char *command)
{
	int	i;

	i = 0;
	if (!command || command[0] != '-')
		return (0);
	while (command[++i])
	{
		if (command[i] != 'n')
			return (0);
	}
	return (1);
}

void	echo_command(char **command)
{
	int		i;
	int		check;

	if (command[1])
		check = check_flag(command[1]);
	i = 1;
	if (!command[i] || !command[i + 1])
	{
		printf("\n");
		return ;
	}
	if (check == 1)
		i = 2;
	while (command[i])
	{
		write(1, command[i], ft_strlen(command[i]));
		if (command[i + 1] != 0)
			write(1, " ", 1);
		i++;
	}
	if (check == 0)
		printf("\n");
}
