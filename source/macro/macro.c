/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 04:49:27 by hozdemir          #+#    #+#             */
/*   Updated: 2023/02/16 06:07:52 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_data *data;

t_bool _macro(char *str)
{
    if(macrocomp(str, "NOQ"))
        return (noq());
	if(macrocomp(str, "QTorF"))
		return (qtorf());
	if(macrocomp(str, "NOR"))
		return (nor());
	if(macrocomp(str, "RTORF"))
		return (rtorf());
	return (FALSE);
}

t_bool macrocomp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != 0 || s2[i] != 0))
	{
		if (s1[i] != s2[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}