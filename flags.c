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

void			ft_initflag(const char *format, t_help *help, int *i)
{
	help->flag_dz = 0;
	help->flag_zr = 0;
	help->flag_ms = 0;
	help->flag_ps = 0;
	help->flag_sp = 0;
	while (format[*i] && (format[*i] == '#' || format[*i] == '0' ||
		format[*i] == '-' || format[*i] == '+' || format[*i] == ' ' ||
		format[*i] == '.'))
	{
		(format[*i] == '#') ? help->flag_dz = 1 : 0;
		(format[*i] == '0') ? help->flag_zr = 1 : 0;
		(format[*i] == '-') ? help->flag_ms = 1 : 0;
		(format[*i] == '+') ? help->flag_ps = 1 : 0;
		(format[*i] == ' ') ? help->flag_sp = 1 : 0;
		(*i)++;
	}
}

void			ft_initconv(t_help *help, int *i, t_env *env, va_list ap)
{
	const char	*format;

	format = env->str;
	if (format[*i] && (format[*i] == 's' || format[*i] == 'S' || 
		format[*i] == 'p' || format[*i] == 'd' || format[*i] == 'D' ||
		format[*i] == 'i' || format[*i] == 'o' || format[*i] == 'O' ||
		format[*i] == 'u' || format[*i] == 'U' || format[*i] == 'x' ||
		format[*i] == 'X' || format[*i] == 'c' || format[*i] == 'C')) // manque h hh l ll j z
	{
		env->nb_arg++;
		help->conv = format[*i];
		ft_useva(env, ap, help);
		(*i)++;
	}
}
