/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:55:33 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/23 03:20:52 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

void	reload_old_path(void)
{
	char	*path;
	char	buff[4096 + 1];

	path = ft_strjoin("OLDPWD=", getcwd(buff, 4096));
	add_export(path);
	add_env(path);
	free(path);
}

void	cd_command(char **command)
{
	int		i;

	i = 1;
	if (command[i] == 0)
	{
		reload_old_path();
		chdir(getenv("HOME"));
	}
	else
	{
		reload_old_path();
		if (chdir(command[i]) == -1)
		{
			perror("cd");
			return ;
		}
	}
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
