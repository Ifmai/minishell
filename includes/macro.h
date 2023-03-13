/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 04:49:55 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 19:56:13 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# include "ifmai.h"

typedef enum s_bool
{
	TRUE = 1,
	FALSE = 0
}			t_bool;

int		_macro(char *str);
t_bool	reset_quoete(void);
t_bool	reset_value(void);
t_bool	macrocomp(const char *s1, const char *s2);
t_bool	qtorf(void);
t_bool	rtorf(void);
t_bool	nor(void);
t_bool	noq(void);
t_bool	rtorft(void);
t_bool	qtorft(void);
t_bool	noqt(void);

#endif