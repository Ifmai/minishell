/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 04:49:55 by hozdemir          #+#    #+#             */
/*   Updated: 2023/03/13 17:39:43 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

#include "ifmai.h"

typedef enum s_bool
{
	TRUE = 1,
	FALSE = 0
}			t_bool;

int	_macro(char *str);
t_bool	reset_quoete();
t_bool	reset_value();
t_bool	macrocomp(const char *s1, const char *s2);
t_bool	qtorf();
t_bool	rtorf();
t_bool	nor();
t_bool	noq();
t_bool	rtorft();
t_bool	qtorft();
t_bool	noqt();

#endif