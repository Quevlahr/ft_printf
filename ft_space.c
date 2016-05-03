/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:24:40 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:19:16 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_space_str(char *str, t_env *env)
{
	if (env->flag_sp == 1)
	{
		ft_putchar(' ');
		env->nb_char++;
		(env->nb_sp > 0) ? env->nb_sp-- : 0;
	}
	if (env->flag_pt > 0 && env->conv != 's')
	{
		int i = 0;
		while (i < (env->flag_pt - (int)ft_strlen(str)))
		{
			ft_putchar('0');
			i++;
			env->nb_char++;
		}
	}
	if (env->flag_ms == 1)
	{
		flag_dz_str(env, str);
		if (env->flag_pt != -1 || ft_strcmp(str, "0") != 0)
			ft_putstr(str);
		else
			env->nb_char--;
		ft_putarg_str(env, str);
	}
	else if (env->flag_dz == 1 && env->flag_zr == 0)
	{
		ft_putarg_str(env, str);
		flag_dz_str(env, str);
		if (env->flag_pt != -1 || ft_strcmp(str, "0") != 0)
			ft_putstr(str);
		else
			env->nb_char--;
	}
	else
	{
		flag_dz_str(env, str);
		ft_putarg_str(env, str);
		if (env->flag_pt != -1 || ft_strcmp(str, "0") != 0)
			ft_putstr(str);
		else
			env->nb_char--;
	}
}

void			ft_space_int(long long a, t_env *env)
{
	int			i = 0;
	if (env->flag_ms == 1)
	{
		if (a < 0 || env->flag_ps == 1)
		{
			(a < 0) ? ft_putchar('-') : ft_putchar('+');
			(a < 0) ? a *= -1 : 0;
			env->flag_ps = -1;
			env->nb_char++;
		}
		while (i < (env->flag_pt - ft_nbrlen(a)))
		{
			ft_putchar('0');
			i++;
			env->nb_char++;
		}
	}
	if (env->flag_sp == 1 && env->flag_ps == 0 && a > 0)
	{
		ft_putchar(' ');
		env->nb_char++;
		(env->nb_sp > 0) ? env->nb_sp-- : 0;
	}
	if ((env->flag_ps == 1 || a < 0) && env->flag_pt > 0)
	{
		ft_putarg_ll(env, a);
		a *= (a < 0) ? -1 : 1;
		ft_putnbr_ll(a);
	}
	else if (env->flag_zr == 1 && (env->flag_ps == 1 || a < 0))
	{
		(a < 0) ? ft_putchar('-') : ft_putchar('+');
		ft_putarg_ll(env, a);
		(a < 0) ? a *= -1 : 0;
		ft_putnbr_ll(a);
	}
	else if (env->flag_ms == 1)
	{
		(env->flag_ps == 1 && a >= 0) ? ft_putchar('+') : 0;
		ft_putnbr_ll(a);
		ft_putarg_ll(env, a);
	}
	else
	{
		ft_putarg_ll(env, a);
		(env->flag_ps == 1 && a >= 0) ? ft_putchar('+') : 0;
		if (env->flag_pt != -1 || a != 0)
			ft_putnbr_ll(a);
		else
			env->nb_char--;
		// (env->flag_pt != -1 && a != 0) ? ft_putnbr_ll(a) : 0;
		// ft_putnbr_ll(a);
	}
}

void			ft_space_char(char c, t_env *env)
{
	int			i;

	i = 0;
	if (env->flag_ms == 1)
	{
		ft_putchar(c);
		while (i < env->nb_sp - 1)
		{
			ft_putchar(' ');
			i++;
			env->nb_char++;
		}
	}
	else
	{
		while (i < env->nb_sp - 1)
		{
			ft_putchar(' ');
			i++;
			env->nb_char++;
		}
		ft_putchar(c);
	}
	env->nb_char++;
}
