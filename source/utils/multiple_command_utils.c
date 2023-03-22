/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_command_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:06:51 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/22 09:08:07 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

t_bool	is_it_builtinz_2(char **command)
{
	if (macrocomp(command[0], "env"))
		return (TRUE);
	else if (macrocomp(command[0], "pwd"))
		return (TRUE);
	else if (macrocomp(command[0], "cd"))
		return (TRUE);
	else if (macrocomp(command[0], "exit"))
		return (TRUE);
	else if (macrocomp(command[0], "unset"))
		return (TRUE);
	return (FALSE);
}

int	is_it_builtinz(char **command)
{
	if (chardb_len(command) == 0)
		return (FALSE);
	if (macrocomp(command[0], "echo"))
		return (TRUE);
	else if (macrocomp(command[0], "export"))
		return (TRUE);
	else if (macrocomp(command[0], "env"))
		return (TRUE);
	return (is_it_builtinz_2(command));
}

void	close_pipe(int i)
{
	if (i == g_data->dvd_str->pipe_count)
		close_pipe_fd();
	else if (i > 0 && i < g_data->dvd_str->pipe_count)
	{
		close(g_data->fd[i - 1][0]);
		close(g_data->fd[i - 1][1]);
	}
}

void	execute_builtinz(char *select, char **command, int flag)
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
	else if (macrocomp(select, "cd"))
		cd_command(command);
	else if (macrocomp(select, "unset"))
		unset_command(command);
}
