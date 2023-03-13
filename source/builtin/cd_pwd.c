/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:55:33 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 20:00:02 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

void	cd_command(char **command)
{
	int	i;

	i = 1;
	if (command[i] == 0)
		chdir(getenv("HOME"));
	else if (ft_strchr(command[i], 32) || command[i + 1] != 0)
		printf("cd: string not in pwd: %s\n", command[i]);
	else
		chdir(command[i]);
}

void	pwd_command(char **command)
{
	char	*str;

	if (command[1] != 0)
		printf("pwd: too many arguments");
	str = ft_calloc(1024, 1);
	str = getcwd(str, 1024);
	if (!str)
		printf(".\n");
	else
		printf("%s\n", str);
	free(str);
}
