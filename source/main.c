/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:38:40 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/22 09:21:26 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ifmai.h"

t_data	*g_data;

int	main(int ac, char **av, char **env)
{
	if (ac != 1 || av[1])
		return (0);
	g_data = malloc(sizeof(t_data));
	g_data->env = ft_env(env);
	define_struct();
	export_create();
	//create_path();
	minishell_loop();
}
