/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 21:19:59 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/25 18:41:16 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		flag_rien(t_env *env)
{
	env->nb_sp--;
	env->nb_char++;
	(env->flag_ms == 1) ? ft_putchar(env->conv) : 0;
	while (env->nb_sp > 0)
	{
		(env->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
		env->nb_sp--;
		env->nb_char++;
	}
	(env->flag_ms == 0) ? ft_putchar(env->conv) : 0;
}

static void		flag_pourcent(t_env *env, va_list ap)
{
	char		*c;

	c = ft_strnew(1);
	c[0] = '%';
	env->flag_sp = 0;
	env->flag_dz = 0;
	env->flag_pt = 0;
	ft_space_str(c, env);
	ft_strdel(&c);
}

static void		flag_char(t_env *env, va_list ap)
{
	char		c;

	env->flag_sp = 0;
	c = va_arg(ap, int);
	ft_space_char(c, env);
}

static void		flag_wchar(int a, t_env *env, va_list ap)
{
	char		*str;

	str = NULL;
	a = va_arg(ap, int);
	ft_space_wchar(a, env);
}

static void		flag_wstr(t_env *env, va_list ap)
{
	wchar_t		*a;
	wchar_t		*tmp;
	int			nul;
	int			i;

	i = 0;
	nul = 0;
	a = (wchar_t *)va_arg(ap, char *);
	tmp = NULL;
	if (a == NULL && ++nul)
		ft_null_wstr(&a, env);
	if (env->flag_pt == -1)
		while (env->nb_sp > 0)
		{
			(env->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
			env->nb_sp--;
			env->nb_char++;
		}
	else
	{
		if (env->flag_pt > 0)
		{
			tmp = ft_modifwstr(a, env);
			(env->flag_ms == 0) ? ft_putarg_wstr(env, tmp) : 0;
			while (tmp[i])
			{
				ft_space_wchar(tmp[i], env);
				i++;
			}
			(env->flag_ms == 1) ? ft_putarg_wstr(env, tmp) : 0;

		}
		else
		{
			(env->flag_ms == 0) ? ft_putarg_wstr(env, a) : 0;
			while (a[i])
			{
				ft_space_wchar(a[i], env);
				i++;
			}
			(env->flag_ms == 1) ? ft_putarg_wstr(env, a) : 0;
		}
		free(tmp);
		tmp = NULL;
	}
	if (nul > 0)
	{
		free(a);
		a = NULL;
	}
}

static void		flag_unsigned(unsigned long long a, t_env *env, va_list ap)
{
	env->flag_ps = 0;
	env->flag_sp = 0;
	if (env->flag_hh == 1 && env->conv != 'U')
		a = (unsigned char)va_arg(ap, unsigned int);
	else if (env->flag_h == 1 && env->conv != 'U')
		a = (unsigned short)va_arg(ap, unsigned int);
	else if (env->flag_l == 0 && env->flag_ll == 0 && env->flag_j == 0 &&
			env->conv != 'U')
		a = va_arg(ap, unsigned int);
	else if (env->flag_l == 1 || env->conv == 'U')
		a = va_arg(ap, unsigned long);
	else if (env->flag_ll == 1 || env->flag_j == 1)
		a = va_arg(ap, unsigned long long);
	ft_space_int(a, env);
	if (env->flag_ms == 0 && env->flag_ps == 1)
		env->nb_char++;
}

static void		flag_octal(long long a, t_env *env, va_list ap)
{
	char		*str;

	env->flag_sp = 0;
	// if (env->flag_hh == 1)
	// 	a = (char)va_arg(ap, int);
	// else if (env->flag_h == 1)
	// 	a = (short)va_arg(ap, int);
	if (env->flag_l == 1 || env->conv == 'O')
		a = va_arg(ap, long);
	else if (env->flag_ll == 1)
		a = va_arg(ap, long long);
	else
		a = va_arg(ap, int);
	if (env->conv == 'O' && a > -2147483648 && a < 0)
		str = ft_itoabase_ui(a, 8, 0);
	else if (env->flag_hh == 1 && env->conv != 'O')
		str = ft_itoabase_uc(a, 8, 0);
	else if (env->flag_h == 1 && env->conv != 'O')
		str = ft_itoabase_us(a, 8, 0);
	else
		str = ft_itoabase_ull(a, 8, 0);
	if (env->flag_pt > 0 && ft_strcmp(str, "0") == 0)
	{
		env->flag_dz = 0;
		ft_strdel(&str);
		str = ft_strnew(0);
	}
	if (env->flag_dz == 1 && env->flag_pt <= 0)
	{
		if (ft_strcmp(str, "0") != 0)
			env->flag_pt = 1 + ft_strlen(str);
		else
			env->flag_pt = 1;
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
	if (env->conv == 'p')
	{
		env->flag_dz = 1;
		a = (long long)va_arg(ap, void*);
	}
	else if (env->flag_l == 1)
		a = va_arg(ap, long);
	else if (env->flag_ll == 1)
		a = va_arg(ap, long long);
	else if (env->flag_j == 1)
		a = va_arg(ap, unsigned long long);
	else
		a = va_arg(ap, int);
	if (a > -2147483648 && env->flag_j == 0)
		value = a < 0 ? 4294967296 + (long long)a : (long long)a;
	else
		value = a < 0 ? ULONG_MAX + 1 + (long long)a : (long long)a;
	if (env->flag_hh == 1)
		str = ft_itoabase_uc(value, 16, env->maj);
	else if (env->flag_h == 1)
		str = ft_itoabase_us(value, 16, env->maj);
	else
		str = ft_itoabase_ull(value, 16, env->maj);

	if (env->flag_pt != 0 && ft_strcmp(str, "0") == 0 && env->conv != 'p')
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
	int			i;

	i = 0L;
	env->flag_dz = 0;
	if (env->flag_hh == 1 && env->conv != 'D')
		a = (char)va_arg(ap, int);
	else if (env->flag_h == 1 && env->conv != 'D')
		a = (short)va_arg(ap, int);
	else if (env->flag_l == 1)
		a = va_arg(ap, long);
	else if (env->flag_ll == 1 || env->flag_j == 1 || env->flag_z == 1 ||
			env->conv == 'D')
		a = va_arg(ap, long long);
	else
		a = va_arg(ap, int);
	i += a;
	if (a == i && env->conv == 'D')
		env->flag_d = 1;
	ft_space_int(a, env);
	if (env->flag_ms == 0 && (a < 0 || (a >= 0 && env->flag_ps == 1)))
		env->nb_char++;
}

static void		flag_str(t_env *env, va_list ap)
{
	int			nul;
	char		*a;
	char		*tmp;

	nul = 0;
	env->flag_dz = 0;
	env->flag_sp = 0;
	tmp = NULL;
	a = va_arg(ap, char *);
	if (a == NULL && env->flag_pt != -1 && ++nul)
		ft_null_str(&a, env);
	if (env->flag_pt == -1)
	{
		while (env->nb_sp > 0)
		{
			(env->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
			env->nb_sp--;
			env->nb_char++;
		}
	}
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
	if (nul > 0)
		ft_strdel(&a);
}

void			ft_useva(t_env *env, va_list ap)
{
	if (env->conv == 's')
		flag_str(env, ap);
	else if (env->conv == 'S')
		flag_wstr(env, ap);
	else if (env->conv == 'p' || env->conv == 'x' || env->conv == 'X')
		flag_hexa(0, env, ap);
	else if (env->conv == 'd' || env->conv == 'D' || env->conv == 'i')
		flag_int(0, env, ap);
	else if (env->conv == 'o' || env->conv == 'O')
		flag_octal(0, env, ap);
	else if (env->conv == 'u' || env->conv == 'U')
		flag_unsigned(0, env, ap);
	else if (env->conv == 'c')
		flag_char(env, ap);
	else if (env->conv == 'C')
		flag_wchar(0, env, ap);
	else if (env->conv == '%')
		flag_pourcent(env, ap);
	else
		flag_rien(env);
}
