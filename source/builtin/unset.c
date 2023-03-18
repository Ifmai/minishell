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
int get_index(const char *str)
{
    int i = 0;
    while (str[i] && str[i] != '=') {
        i++;
    }
    return i;
}

void delete_env(const char *varname)
{
    int env_len = chardb_len(g_data->env);
    char **new_env = (char **)malloc(sizeof(char *) * (env_len + 1));
    if (new_env == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    int j = 0;
    for (int i = 0; i < env_len; i++) {
        int index = get_index(g_data->env[i]);
        if (ft_strncmp(g_data->env[i], varname, index) != 0) {
            new_env[j++] = g_data->env[i];
        } 
    }
    new_env[j] = NULL;
    g_data->env = new_env;
}

void unset_command(char **args)
{
    if (args[1] == NULL) {
        printf("unset: Too few arguments.\n");
        return;
    }
    for (int i = 1; args[i] != NULL; i++) {
        delete_env(args[i]);
    }
}
