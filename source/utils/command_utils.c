/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:58:54 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/21 19:58:44 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

void	delete_qoute(void)
{
	t_lexer	*iter;
	char	*temp;
	int		i;

	i = 0;
	iter = g_data->dvd_str->lexer;
	while (iter != NULL)
	{
		temp = edit_data(iter->str, TRUE, TRUE);
		free(iter->str);
		iter->str = ft_strdup(temp);
		free(temp);
		iter = iter->next;
	}
}

char	*true_command(char **command)
{
	int		i;
	char	*true_path;

	i = 0;
	if (access(command[0], F_OK) != -1)
	 	return (ft_strdup(command[0]));
	else if(command[0][0] == '/')
		return (0);
	while (g_data->path[i] != 0)
	{
		true_path = ft_strdup(g_data->path[i]);
		true_path = new_str_join(true_path, "/");
		true_path = new_str_join(true_path, command[0]);
		if (access(true_path, F_OK) != -1)
			return (true_path);
		free(true_path);
		i++;
	}
	return (0);
}

char	**command_create(void)
{
	int			len;
	t_lexer		*iter;
	char		**command;

	iter = g_data->dvd_str->lexer;
	len = -1;
	while (++len < g_data->command_count && iter != NULL)
		iter = iter->next;
	len = len_list(iter);
	command = ft_calloc(sizeof(char *), len + 1);
	if (!command || !iter)
		return (0);
	len = 0;
	while (iter != NULL && !(iter->str[0] == '|'))
	{
		command[len] = ft_strdup(iter->str);
		g_data->command_count++;
		len++;
		iter = iter->next;
	}
	if (iter != NULL && (iter->str[0] == '|'))
		g_data->command_count++;
	return (command);
}

char	*new_str_join(char *s1, char *s2)
{
	char	*back;
	size_t	total_len;

	if (!s1 || !s2)
		return (0);
	total_len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	back = malloc(total_len * sizeof(char));
	if (!back)
		return (0);
	ft_strlcpy(back, s1, ft_strlen(s1) + 1);
	ft_strlcat(back, s2, total_len);
	free(s1);
	return (back);
}
