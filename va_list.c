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

static void		flag_hexa(int a, t_env *env, va_list ap, int maj)
{
	char		*str;
	char		*tmp;
	long long	value;

	tmp = NULL;
	if (env->flag_l == 0 && env->flag_ll == 0)
		a = va_arg(ap, int);
	else if (env->flag_l == 1)
		a = va_arg(ap, long);
	else if (env->flag_ll == 1)
		a = va_arg(ap, long long);
	value = a < 0 ? 4294967296 + (long long)a : (long long)a;
	str = ft_itoabase_ull(value, 16, maj);
	ft_space_str(str, env, 0);
	ft_strdel(&str);
}

static void		flag_int(long long a, t_env *env, va_list ap)
{
	if (env->flag_l == 0 && env->flag_ll == 0)
	{
		a = va_arg(ap, int);
		ft_space_int(a, env, 0);
	}
	else if (env->flag_l == 1)
	{
		a = va_arg(ap, long);
		ft_space_long(a, env, 0);
	}
	else if (env->flag_ll == 1)
	{
		a = va_arg(ap, long long);
		ft_space_ll(a, env, 0);
	}
	if (a < 0)
		env->nb_char++;
}

static void		flag_str(t_env *env, va_list ap)
{
	char		*a;

	a = va_arg(ap, char *);
	if (a == NULL)
		ft_null_str(env);
	else
		ft_space_str(a, env, 0);
}

void			ft_useva(t_env *env, va_list ap)
{
	char		*c;

	c = ft_strnew(1);
	c[0] = '%';
	(env->conv == 's') ? flag_str(env, ap) : 0;
	(env->conv == 'd') ? flag_int(0, env, ap) : 0;
	(env->conv == 'x') ? flag_hexa(0, env, ap, 0) : 0;
	(env->conv == 'X') ? flag_hexa(0, env, ap, 1) : 0;
	if (env->conv == '%')
		ft_space_str(c, env, 0); // passe pas le moulitest avec &(env->conv)
	ft_strdel(&c);
	// (env->nb_sp != 0) ? flag_digit(1, env) : 0;
}
