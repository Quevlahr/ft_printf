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

void			flag_digit(int a, t_env *env, t_help *help)
{
	if (help->flag_zr == 1 && help->flag_ms == 0)
		while (a < help->nb_sp)
		{
			ft_putchar('0');
			a++;
			env->nb_char++;
		}
	else
	{
		if (help->flag_ms == 1)
		{
			env->nb_char++;
			ft_putchar('%');
		}
		while (a < help->nb_sp)
		{
			ft_putchar(' ');
			a++;
			env->nb_char++;
		}
	}
}

void			flag_hexa(int a, t_env *env, va_list ap, int maj)
{
	char		*str;

	a = va_arg(ap, int);
	str = ft_itoabase(a, 16, maj);
	ft_putstr(str);
	env->nb_char += ft_strlen(str);
	ft_strdel(&str);
}

void			flag_int(int a, t_env *env, va_list ap)
{
	a = va_arg(ap, int);
	ft_putnbr(a);
	env->nb_char += ft_nbrlen(a);
}

void			flag_str(char *a, t_env *env, va_list ap)
{
	a = va_arg(ap, char*);
	ft_putstr(a);
	env->nb_char += ft_strlen(a);
	ft_strdel(&a);
}

void			ft_useva(t_env *env, va_list ap, t_help *help)
{
	(help->conv == '\0') ? ft_error(NULL) : 0;
	(help->conv == 'd') ? flag_int(0, env, ap) : 0;
	(help->conv == 's') ? flag_str(NULL, env, ap) : 0;
	(help->conv == 'x') ? flag_hexa(0, env, ap, 0) : 0;
	(help->conv == 'X') ? flag_hexa(0, env, ap, 1) : 0;
}
