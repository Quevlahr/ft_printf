/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 19:52:18 by quroulon          #+#    #+#             */
/*   Updated: 2016/04/04 19:52:27 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_initflag(const char *format, t_help *help, int *j)
{
	help->flag_dz = 0;
	help->flag_zr = 0;
	help->flag_ms = 0;
	help->flag_ps = 0;
	help->flag_sp = 0;
	while (format[*j] && (format[*j] == '#' || format[*j] == '0' ||
		format[*j] == '-' || format[*j] == '+' || format[*j] == ' ' ))
	{
		(format[*j] == '#') ? help->flag_dz = 1 : 0;
		(format[*j] == '0') ? help->flag_zr = 1 : 0;
		(format[*j] == '-') ? help->flag_ms = 1 : 0;
		(format[*j] == '+') ? help->flag_ps = 1 : 0;
		(format[*j] == ' ') ? help->flag_sp = 1 : 0;
		(*j)++;
	}
}

void			ft_initlastarg(t_help *help)
{
	help->conv = '0';
	help->flag_dz = 0;
	help->flag_zr = 0;
	help->flag_ms = 0;
	help->flag_ps = 0;
	help->flag_sp = 0;
}