/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 19:52:18 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:09:02 by quroulon         ###   ########.fr       */
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
	while (format[*i] && (ft_verifchar(format[*i]) == 2 || ft_isdigit(format[*i]) == 1))
	{
		if (ft_verifbase(env, i) == 1)
		{
			ft_veriflh(env, i, &tmpl, &tmph);
			if (ft_isdigit(format[*i]) == 1)
				ft_initdigit(env, i);
			if (format[*i] == '.')
			{
				(*i)++;
				if (ft_isdigit(format[*i]) != 1)
					env->flag_pt = -1;
				else if (ft_isdigit(format[*i]) == 1 || format[*i] == '-' || format[*i] == '+')
				{
					env->flag_pt = ft_atoi(format + (*i));
					(*i) += ft_nbrlen(ft_atoi(format + (*i)));
					(env->flag_pt == 0) ? env->flag_pt = -1 : 0;
				}
			}
		}
	}
	(env->flag_ms == 1) ? env->flag_zr = 0 : 0;
	(env->flag_ps == 1) ? env->flag_sp = 0 : 0;
}

void			ft_initconv(int *i, t_env *env, va_list ap)
{
	const char	*format;

	format = env->str;
	if (format[*i] && ft_verifchar(format[*i]) == 1)
	{
		(format[*i] >= 'A' && format[*i] <= 'Z') ? env->maj = 1 : 0;
		env->nb_arg++;
		env->conv = format[*i];
		ft_useva(env, ap);
		(*i)++;
	}
}
