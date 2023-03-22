/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:57:48 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/22 22:26:58 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

void	file_operations(char *redir_param, char *symbol, t_redirection *redir)
{
	char	*edited_param;
	char	*cwd;
	
	(void)redir;
	if (redir_param[0] == '/')
		edited_param = redir_param;
	else
	{
		cwd = add_symbol();
		edited_param = ft_strjoin(cwd, redir_param);
		free(cwd);
	}
	assign_in_out(edited_param, symbol, redir_param);
	free(edited_param);
}

char	**change_command(char **command, int i)
{
	char	**new_command;
	int		j;
	int		index;

	j = 0;
	index = 0;
	new_command = ft_calloc(sizeof(char *), chardb_len(command) - 1);
	while (command[j])
	{
		if (j == i)
			j += 2;
		else
		{
			new_command[index] = ft_strdup(command[j]);
			index++;
			j++;
		}
	}
	free_command_db(command);
	return (new_command);
}

char	**redirection(char **command)
{
	int		i;
	char	*temp;

	i = 0;
	while (command[i] != 0 && command[i + 1])
	{
		if (is_redir_symbol_string(command[i]))
		{
			temp = edit_data(command[i + 1], TRUE, TRUE);
			file_operations(temp, command[i], g_data->_redirection);
			if(g_data->_redirection->redir_control == 0)
				return NULL;
			command = change_command(command, i);
			free(temp);
		}
		else
			i++;
	}
	return (command);
}
