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

void			flag_digit(int a, t_env *env)
{
	if (env->flag_zr == 1 && env->flag_ms == 0)
		while (a < env->nb_sp)
		{
			ft_putchar('0');
			a++;
			env->nb_char++;
		}
	else
	{
		if (env->flag_ms == 1)
		{
			env->nb_char++;
			ft_putchar('%');
		}
		while (a < env->nb_sp)
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
	char		*tmp;

	tmp = NULL;
	a = va_arg(ap, int);
	str = ft_itoabase(a, 16, maj);
	if (a < 0)
	{
		tmp = str;
		str = ft_negative_hexa(tmp, maj);
		ft_strdel(&tmp);
	}
	ft_space_str(str, env, 0);
	ft_strdel(&str);
}

void			flag_int(int a, t_env *env, va_list ap)
{
	a = va_arg(ap, int);
	if (a < 0)
		env->nb_char++;
	ft_space_int(a, env, 0);

}

void			flag_str(char *a, t_env *env, va_list ap)
{
	a = va_arg(ap, char*);
	ft_space_str(a, env, 0);
	ft_strdel(&a);
}

void			ft_useva(t_env *env, va_list ap)
{
	(env->conv == 's') ? flag_str(NULL, env, ap) : 0;
	(env->conv == 'd') ? flag_int(0, env, ap) : 0;
	(env->conv == 'x') ? flag_hexa(0, env, ap, 0) : 0;
	(env->conv == 'X') ? flag_hexa(0, env, ap, 1) : 0;
	if (env->conv == '%')
		ft_space_str("%", env, 0); // passe pas le moulitest avec &(env->conv)
	// (env->nb_sp != 0) ? flag_digit(1, env) : 0;
}
