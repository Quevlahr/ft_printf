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
	a = va_arg(ap, int);
	value = a < 0 ? 4294967296 + (long long)a : (long long)a;
	str = ft_itoabase_ull(value, 16, maj);
	ft_space_str(str, env, 0);
	ft_strdel(&str);
}

static void		flag_int(int a, t_env *env, va_list ap)
{
	a = va_arg(ap, int);
	if (a < 0)
		env->nb_char++;
	ft_space_int(a, env, 0);

}

static void		flag_str(t_env *env, va_list ap)
{
	char		*a;

	a = va_arg(ap, char *);
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
