/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_select_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:30:06 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/23 04:29:37 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

t_bool	is_it_builtins_2(char **command)
{
	if (macrocomp(command[0], "env"))
		return (TRUE);
	else if (macrocomp(command[0], "pwd"))
		return (TRUE);
	else if (macrocomp(command[0], "cd"))
	{
		cd_command(command);
		return (TRUE);
	}
	else if (macrocomp(command[0], "exit"))
	{
		exit_command(command);
		return (TRUE);
	}
	else if (macrocomp(command[0], "unset"))
	{
		unset_command(command);
		return (TRUE);
	}
	return (FALSE);
}

int	is_it_builtins(char **command)
{
	if (chardb_len(command) == 0)
		return (FALSE);
	if (macrocomp(command[0], "echo"))
		return (TRUE);
	else if (macrocomp(command[0], "export"))
	{
		export_command(command, 1);
		return (TRUE);
	}
	else if (macrocomp(command[0], "env"))
	{
		env_command(command, 1);
		return (TRUE);
	}
	return (is_it_builtins_2(command));
}

void	execute_builtins(char *select, char **command, int flag)
{
	if (macrocomp(select, "echo"))
		echo_command(command);
	else if (macrocomp(select, "pwd"))
		pwd_command(command);
	else if (macrocomp(select, "export"))
		export_command(command, flag);
	else if (macrocomp(select, "env"))
		env_command(command, flag);
	else if (macrocomp(select, "exit"))
		exit_command(command);
}
