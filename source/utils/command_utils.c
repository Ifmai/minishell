/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:58:54 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/10 20:32:13 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

int	is_it_builtins(char **command)
{
	if(chardb_len(command) == 0)
		return (FALSE);
	if(macrocomp(command[0], "echo"))
		return (TRUE);
	else if(macrocomp(command[0], "export"))
	{
		export_command(command);
		return (TRUE);
	}
	else if(macrocomp(command[0], "exit"))
		return (TRUE);
	else if(macrocomp(command[0], "env"))
		return (TRUE);
	else if(macrocomp(command[0], "pwd"))
		return (TRUE);
	else if(macrocomp(command[0], "cd"))
	{
		cd_command(command);
		return (TRUE);
	}
	return (FALSE);
}

void	delete_qoute() // "sofıdjpsdfk"sapdkpoasd gibi bir örnekte silmiyor bu düzeltilcek.
{
	t_lexer	*iter;
	char	*temp;
	int		i;

	i = 0;

	iter = data->dvd_str->lexer;
	while(iter != NULL)
	{
		temp = edit_data(iter->str);
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
	char	*edit_command;

	edit_command = edit_data(command[0]);
	i = 0;
	while (data->path[i] != 0)
	{
		true_path = ft_strdup(data->path[i]);
		true_path = new_str_join(true_path, "/");
		true_path = new_str_join(true_path, edit_command);
		if(access(true_path, F_OK) != -1 )
			return (true_path);
		free(true_path);
		i++;
	}
	free(edit_command);
	return (0);
}

char	**command_create()
{
	int			len;
	t_lexer		*iter;
	char		**command;

	iter = data->dvd_str->lexer;
    len = -1;
    while(++len < data->command_count && iter != NULL)
        iter = iter->next;
	len = len_list(iter);
	command = ft_calloc(sizeof(char *) , len + 1);
    if(!command || !iter)
        return (0);
    len = 0;
	while(iter != NULL && !(iter->str[0] == '|'))
	{
		command[len] = ft_strdup(iter->str);
        data->command_count++;
        len++;
        iter = iter->next;
	}
	if(iter != NULL && (iter->str[0] == '|'))
		data->command_count++;
	return (command);
}

/* char	**command_create()
{
	int			len;
	char		**command;

	len = len_list(data->dvd_str->lexer);
	command = ft_calloc(sizeof(char *) , len + 1);
    if(!command)
        return (0);
    len = 0;
	while(data->dvd_str->lexer != NULL && !(data->dvd_str->lexer->str[0] == '|' 
		|| data->dvd_str->lexer->str[0] == '<' || data->dvd_str->lexer->str[0] == '>'))
	{
		command[len] = ft_strdup(data->dvd_str->lexer->str);
        len++;
        data->dvd_str->lexer = data->dvd_str->lexer->next;
	}
	if(data->dvd_str->lexer != NULL && (data->dvd_str->lexer->str[0] == '|' 
		|| data->dvd_str->lexer->str[0] == '<' || data->dvd_str->lexer->str[0] == '>'))
		data->dvd_str->lexer = data->dvd_str->lexer->next;
	return (command);
} */

char	*new_str_join(char  *s1, char  *s2)
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
