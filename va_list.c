/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 21:19:59 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/06 18:41:16 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		flag_char(t_env *env, va_list ap)
{
	char		c;

	env->flag_sp = 0;
	c = va_arg(ap, int);
	ft_space_char(c, env);
}

static void		flag_unsigned(long long a, t_env *env, va_list ap)
{
	env->flag_ps = 0;
	env->flag_sp = 0;
	if (env->flag_hh == 1 && env->conv != 'U')
		a = (unsigned char)va_arg(ap, unsigned int);
	else if (env->flag_h == 1 && env->conv != 'U')
		a = (unsigned short)va_arg(ap, unsigned int);
	else if (env->flag_l == 0 && env->flag_ll == 0 && env->flag_j == 0 && env->conv != 'U')
		a = va_arg(ap, unsigned int);
	else if (env->flag_l == 1 || env->conv == 'U')
		a = va_arg(ap, unsigned long);
	else if (env->flag_ll == 1 || env->flag_j == 1)
		a = va_arg(ap, unsigned long long);
	// (a < 0 && (env->flag_ll == 1 || env->flag_l == 1)) ? a -= (4294967296 * 2147483648) : 0;
	// printf("%lld\n", a);
	// (a < 0) ? a += ULONG_MAX + 1: 0;
	ft_space_int(a, env);
	if (env->flag_ms == 0 && (a < 0 || (a >= 0 && env->flag_ps == 1)))
		env->nb_char++;
}

static void		flag_octal(long long a, t_env *env, va_list ap)
{
	char		*str;

	env->flag_sp = 0;
	if (env->flag_l == 0 && env->flag_ll == 0)
		a = va_arg(ap, int);
	else if (env->flag_l == 1)
		a = va_arg(ap, long);
	else if (env->flag_ll == 1)
		a = va_arg(ap, long long);
	str = ft_itoabase_ui(a, 8, 0);
	if (env->flag_pt > 0 && ft_strcmp(str, "0") == 0)
	{
		env->flag_dz = 0;
		ft_strdel(&str);
		str = ft_strnew(0);
	}
	ft_space_str(str, env);
	ft_strdel(&str);
}

static void		flag_hexa(long long a, t_env *env, va_list ap)
{
	char		*str;
	char		*tmp;
	long long	value;

	tmp = NULL;
	env->flag_sp = 0;
	if (env->flag_l == 0 && env->flag_ll == 0 && env->flag_j == 0)
		a = va_arg(ap, int);
	else if (env->flag_l == 1)
		a = va_arg(ap, long);
	else if (env->flag_ll == 1 || env->flag_j == 1)
		a = va_arg(ap, long long);
	if (a > -2147483648)
		value = a < 0 ? 4294967296 + (long long)a : (long long)a;
	else
		value = a < 0 ? ULONG_MAX + 1 + (long long)a : (long long)a;
	str = ft_itoabase_ull(value, 16, env->maj);
	if (env->flag_pt != 0 && ft_strcmp(str, "0") == 0)
	{
		env->flag_dz = 0;
		ft_strdel(&str);
		str = ft_strnew(0);
	}
	ft_space_str(str, env);
	ft_strdel(&str);
}

static void		flag_int(long long a, t_env *env, va_list ap)
{
	env->flag_dz = 0;
	if (env->flag_hh == 1)
		a = (char)va_arg(ap, int);
	else if (env->flag_h == 1)
		a = (short)va_arg(ap, int);
	else if (env->flag_l == 0 && env->flag_ll == 0 && env->flag_j == 0)
		a = va_arg(ap, int);
	else if (env->flag_l == 1)
		a = va_arg(ap, long);
	else if (env->flag_ll == 1 || env->flag_j == 1)
		a = va_arg(ap, long long);
	ft_space_int(a, env);
	if (env->flag_ms == 0 && (a < 0 || (a >= 0 && env->flag_ps == 1)))
		env->nb_char++;
}

static void		flag_str(t_env *env, va_list ap)
{
	char		*a;
	char		*tmp;

	env->flag_dz = 0;
	env->flag_sp = 0;
	tmp = NULL;
	a = va_arg(ap, char *);
	if (a == NULL)
		ft_null_str(env);
	else
	{
		if (env->flag_pt > 0)
		{
			tmp = ft_modifstr(a, env);
			ft_space_str(tmp, env);
			ft_strdel(&tmp);
		}
		else
			ft_space_str(a, env);
	}
}

void			ft_useva(t_env *env, va_list ap)
{
	char		*c;

	c = ft_strnew(1);
	c[0] = '%';	
	(env->conv == 's') ? flag_str(env, ap) : 0;
	(env->conv == 'd') ? flag_int(0, env, ap) : 0;
	(env->conv == 'x') ? flag_hexa(0, env, ap) : 0;
	(env->conv == 'X') ? flag_hexa(0, env, ap) : 0;
	(env->conv == 'c') ? flag_char(env, ap) : 0;
	(env->conv == 'o') ? flag_octal(0, env, ap) : 0;
	(env->conv == 'u') ? flag_unsigned(0, env, ap) : 0;
	(env->conv == 'U') ? flag_unsigned(0, env, ap) : 0;
	if (env->conv == '%')
	{
		env->flag_sp = 0;
		env->flag_dz = 0;
		env->flag_pt = 0;
		ft_space_str(c, env); // passe pas le moulitest avec &(env->conv)
	}
	ft_strdel(&c);
}
