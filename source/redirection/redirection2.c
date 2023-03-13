/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:30:07 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 21:41:32 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data  *g_data;

char	*add_symbol(void)
{
	char	*cwd;
	char	*added;
	char	buff[4096 + 1];

	cwd = getcwd(buff, 4096);
	added = ft_strjoin(cwd, "/");
	return (added);
}

int	set_std_file(int in_fd, int out_fd)
{
	int	ret;

	ret = 0;
	if (in_fd >= 0)
	{
		if (dup2(in_fd, STDIN_FILENO) == -1)
			ret = -1;
	}

	if (out_fd >= 0)
	{
		if (dup2(out_fd, STDOUT_FILENO) == -1)
			ret = -1;
	}
	return (ret);
}

void	assign_in_out(char *edited_param, char *symbol, char *redir_param)
{
	if (!ft_strncmp("<", symbol, 1))
	{
		if (g_data->in_fd >= 0)
			close(g_data->in_fd);
		if (macrocomp("<<", symbol))
			g_data->in_fd = open("includes/.heredoc.txt", O_RDONLY, 0777);
		else
			g_data->in_fd = open(edited_param, O_RDONLY, 0777);
		if (g_data->in_fd < 0)
		{
			printf("%s: No such file or directory\n", redir_param);
			exit(1);
		}
	}
	else
	{
		if (g_data->out_fd >= 0)
			close(g_data->out_fd);
		if (macrocomp(">>", symbol))
			g_data->out_fd = open(edited_param, O_WRONLY \
			| O_CREAT | O_APPEND, 0777);
		else
			g_data->out_fd = open(edited_param, O_WRONLY \
			| O_CREAT | O_TRUNC, 0777);
		if (g_data->out_fd < 0)
			exit(1);
	}
}