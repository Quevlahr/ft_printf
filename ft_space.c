/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:24:40 by quroulon          #+#    #+#             */
/*   Updated: 2016/04/22 15:24:42 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_space_str(char *str, t_env *env)
{
	// if (env->flag_sp == 1)
	// {
	// 	ft_putchar(' ');
	// 	env->nb_char++;
	// 	(env->nb_sp > 0) ? env->nb_sp-- : 0;
	// }
	if (env->flag_ms == 1)
	{
		flag_dz_str(env, str);
		ft_putstr(str);
		ft_putarg_str(env, str);
	}
	else if (env->flag_dz == 1 && env->flag_zr == 0)
	{
		ft_putarg_str(env, str);
		flag_dz_str(env, str);
		ft_putstr(str);
	}
	else
	{
		flag_dz_str(env, str);
		ft_putarg_str(env, str);
		ft_putstr(str);
	}
}

void			ft_space_int(int a, t_env *env)
{
	if (env->flag_sp == 1 && env->flag_ps == 0 && a > 0)
	{
		ft_putchar(' ');
		env->nb_char++;
		(env->nb_sp > 0) ? env->nb_sp-- : 0;
	}
	if (env->flag_ms == 1)
	{
		(env->flag_ps == 1) ? ft_putchar('+') : 0;
		ft_putnbr(a);
		ft_putarg_int(env, a);
	}
	else
	{
		ft_putarg_int(env, a);
		(env->flag_ps == 1) ? ft_putchar('+') : 0;
		ft_putnbr(a);
	}
}

void			ft_space_long(long a, t_env *env)
{
	if (env->flag_ms == 1)
	{
		(env->flag_ps == 1) ? ft_putchar('+') : 0;
		ft_putnbr(a);
		ft_putarg_long(env, a);
	}
	else
	{
		ft_putarg_long(env, a);
		(env->flag_ps == 1) ? ft_putchar('+') : 0;
		ft_putnbr(a);
	}
}

void			ft_space_ll(long long a, t_env *env)
{
	if (env->flag_ms == 1)
	{
		(env->flag_ps == 1) ? ft_putchar('+') : 0;
		ft_putnbr(a);
		ft_putarg_ll(env, a);
	}
	else
	{
		ft_putarg_ll(env, a);
		(env->flag_ps == 1) ? ft_putchar('+') : 0;
		ft_putnbr(a);
	}
}
