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

void			ft_initflag(const char *format, t_env *env, int *i)
{
	int			tmpl;
	int			tmph;

	tmpl = 0;
	tmph = 0;
	ft_initenv(env);
	while (format[*i] && (format[*i] == '#' || format[*i] == '0' ||
		format[*i] == '-' || format[*i] == '+' || format[*i] == ' ' ||
		format[*i] == '.' || format[*i] == 'l' || format[*i] == 'l' ||
		format[*i] == 'j' || format[*i] == 'h' || format[*i] == 'h' || 
		format[*i] == 'z' || ft_isdigit(format[*i]) == 1))
	{
		ft_isdigit(format[*i]ft_initdigit(env, i) ? ;
		ft_verifbase(env, i);
		ft_veriflh(env, i, &tmpl, &tmph);
		if (format[*i] == '.')
		{
			(*i)++;
			env->flag_pt = ft_atoi(format + (*i));
			(*i) += ft_nbrlen(ft_atoi(format + (*i)));
			(*i)--;
		}
		(*i)++;
	}
	(env->flag_ms == 1) ? env->flag_zr = 0 : 0;
	(env->flag_ps == 1) ? env->flag_sp = 0 : 0;
	// (env->flag_sp == 1 && env->nb_sp == 0) ? env->nb_sp = 1 : 0;
}

void			ft_initconv(int *i, t_env *env, va_list ap)
{
	const char	*format;

	format = env->str;
	if (format[*i] && (format[*i] == 's' || format[*i] == 'S' || 
		format[*i] == 'p' || format[*i] == 'd' || format[*i] == 'D' ||
		format[*i] == 'i' || format[*i] == 'o' || format[*i] == 'O' ||
		format[*i] == 'u' || format[*i] == 'U' || format[*i] == 'x' ||
		format[*i] == 'X' || format[*i] == 'c' || format[*i] == 'C' ||
		format[*i] == '%'))
	{
		(format[*i] >= 'A' && format[*i] <= 'Z') ? env->maj = 1 : 0;
		env->nb_arg++;
		env->conv = format[*i];
		ft_useva(env, ap);
		(*i)++;
	}
}
