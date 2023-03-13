/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:28:33 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 22:46:54 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data	*g_data;

// aklımda ki fikir get_index ile = 'in olduğu index i bulup ona göre strncmp yapıp doğrumu env'de mi değil mi ona bakmak
// sonrasında silmek ancak 1'den çok unset verirse ????
// çalışıyor bu yüzden 10dk da çıkan bu +30 saat uykusuz çalışmakla.

/* int	get_index(char *command)
{
	int	i;

	i = 0;
	while (g_data->env[i][j] && g_data->env[i][j] != '=')
		i++;
	i++;
}

void	delete_env(int index, char *command, int *i, int *j)
{
	while (g_data->env[*i] != 0)
	{
		index = get_index(g_data->env[*i]);
		if (ft_strncmp(g_data->env[*i], command, index))
			(*i)++;
		new[*j] = ft_strdup(g_data->env[*i]);
	}
}

void	unset_command(char **command)
{
	int		i;
	int		index;
	int		x;
	int		j;
	char	**new;

	if (!command[1])
		return ;
	i = 0;
	j = 0;
	x = 0;
	new = ft_calloc(sizeof(char *), \
		chardb_len(g_data->env) - chardb_len(command) - 2);
	while(command[x] != 0)
	{

	}
} */