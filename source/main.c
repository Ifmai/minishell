/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:38:40 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 19:19:17 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ifmai.h"

t_data *data;

int main(int ac, char **av, char **env)
{
	if(ac != 1 || av[1])
	{
		printf("Bro Girmicen Parametre amk");
		return (0);
	}
	data = malloc(sizeof(t_data));
	data->env = ft_env(env);
	define_struct();
	export_create();
	create_path();
	minishell_loop();
}