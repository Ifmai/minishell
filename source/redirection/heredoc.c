/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:12:04 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/21 17:57:30 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

void	wait_limiter(char *limiter, int _fd)
{
	t_bool	var_flag;
	char	*loop;
	char	*input;
	char	*edited_data;

	var_flag = !is_contains_quote(limiter);
	input = readline(">");
	loop = edit_data(limiter, FALSE, TRUE);
	while (!macrocomp(loop, input))
	{
		if (var_flag)
			edited_data = edit_data(input, TRUE, FALSE);
		else
			edited_data = edit_data(input, FALSE, FALSE);
		write(_fd, edited_data, ft_strlen(edited_data));
		write(_fd, "\n", 1);
		free(edited_data);
		free(input);
		free(loop);
		input = readline(">");
		loop = edit_data(limiter, FALSE, TRUE);
	}
	free(loop);
	free(input);
}

void	read_heredoc(char *limiter, int index)
{
	int		fd;
	char	*path;

	path = ft_strjoin("includes/heredoc", ft_itoa(index));
	fd = open(path \
	, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
		exit(1);
	wait_limiter(limiter, fd);
	free(path);
	close(fd);
}

void	init_heredoc(void)
{
	t_lexer		*arg;
	int			index;

	index = 0;
	arg = g_data->dvd_str->lexer;
	while (arg != NULL)
	{
		if (macrocomp(arg->str, "<<") && arg->next)
			read_heredoc(arg->next->str, index);
		if (macrocomp(arg->str, "|"))
			index++;
		arg = arg->next;
	}
}
