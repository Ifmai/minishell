/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:52:20 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/19 08:33:47 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

void	minishell_loop(void)
{
	while(1)
	{
		data->line = readline("uWuShell > ");
		if(data->line[0] == '.')
			break ;
		add_history(data->line);
		divide_string(data->line, data->dvd_str);
	}
}

// execve( path alıyor , command_create(dönen double array), env)
	
// Command Create Deneme kodu.
	/* char **d;
	char **s = command_create();
	int i = 0;
	while(s[i] != 0)
		printf("<<1. command %s >>\n",s[i++]);
	i = 0;
	d = command_create();
	while(d[i] != 0)
		printf("<<2. command %s >>\n",d[i++]); */