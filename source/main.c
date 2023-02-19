/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:38:40 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/18 20:29:45 by hozdemir         ###   ########.fr       */
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
	create_path();
	minishell_loop();
/* 	while(data->dvd_str->lexer != NULL)
	{
		printf("%s.\n",data->dvd_str->lexer->str);
		data->dvd_str->lexer = data->dvd_str->lexer->next;
	} */
}