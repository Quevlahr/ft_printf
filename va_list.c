/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 21:19:59 by quroulon          #+#    #+#             */
/*   Updated: 2016/04/08 21:20:03 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			flag_int(int a, t_arg *arg, t_env env, va_list ap)
{
	ft_putnbr(va_arg(ap, int));
	env.nb_char++;
}

void			flag_str(char *a, t_arg *arg, t_env env, va_list ap)
{
	ft_putstr(va_arg(ap, char*));
	env.nb_char++;
}

void			ft_useva(t_arg *arg, t_env env, va_list ap)
{
	arg = arg->start;
	while (arg->next)
	{
		(arg->conv == 'd') ? flag_int(0, arg, env, ap) : 0;
		(arg->conv == 's') ? flag_str(NULL, arg, env, ap) : 0;
		arg = arg->next;
	}
}
