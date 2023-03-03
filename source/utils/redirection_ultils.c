/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_ultils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:05:01 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/28 14:09:38 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

void    counter_redirection(char *str, t_redirection *redirection , int i)
{
    printf("gelen : %s\n",str);
    while(str[i] != 0)
    {
        if(str[i] == '\"' && redirection->temp_quote == 0)
            redirection->temp_db_quote++;
        else if(str[i] == '\'' && redirection->temp_db_quote == 0)
            redirection->temp_quote++;
        if(str[i] == '<' && _macro("NOQT") \
        && _macro("NORT"))
        {
            if(str[i + 1] == '<')
                redirection->heredoc++;
            else
                redirection->input++;
        }
        if(str[i] == '>' && _macro("NOQT") \
        && _macro("NORT"))
        {
            if(str[i + 1] == '>')
                redirection->appened++;
            else
                redirection->output++;
        }
        if(_macro("QTorFT"))
            _macro("reset_quoete");
        i++;
    }
}