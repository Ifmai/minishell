/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:04:14 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 20:08:35 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

static int	ft_check_str(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isalpha(s[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	new_atoi(const char *s)
{
	int		i;
	long	back;
	int		np;

	back = 0;
	np = 1;
	i = 0;
	while ((s[i] <= 13 && s[i] >= 9) || s[i] == 32)
		i++;
	if (s[i] == 43 || s[i] == 45)
	{
		if (s[i] == 45)
			np *= -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		back = back * 10 + (s[i] - 48) * np;
		if (back > 2147483647)
			return (-1);
		if (back < -2147483648)
			return (0);
		i++;
	}
	return ((int)back);
}

void	exit_command(char **command)
{
	int	exit_value;

	if (!command[1])
		exit (data->_var);
	else if (chardb_len(command) > 2)
	{
		printf("bash: exit: too many arguments");
		exit (1);
	}
	else if (command[1])
	{
		if (ft_check_str(command[1]))
		{
			printf("bash: exit: %s: numeric argument required\n", command[1]);
			exit(255);
		}
	exit_value = new_atoi(command[1]);
		if (exit_value == -1)
		{
			printf("bash: exit: %s: numeric argument required\n", command[1]);
			exit(255);
		}
		exit(exit_value);
	}
}
