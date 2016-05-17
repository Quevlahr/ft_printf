/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:24:40 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/17 20:09:31 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

UI				ft_givebit(UI pos, UI n)
{
    return ((1 << pos) & n) >> pos;
}

int				ft_replacebit(UI *bit, int a, int cpt, t_env *env)
{
	int			i;
	int			seis;

	seis = 0;
	while (cpt - 6 * seis > 0)
	{
		i = (cpt - 6 * seis < 6) ? cpt - 6 * seis : 6;
		(bit[0] == 0) ? i = 7 : 0;
		while (i > 0)
		{
			bit[seis] = bit[seis] << 1;
			bit[seis] = bit[seis] ^ ft_givebit((i - 1) + 6 * seis, a);
			i--;
		}
		env->nb_char++;
		seis++;
	}
	return(0);
}

void			ft_space_wchar(int a, t_env *env)
{
	UI			bit[4];

	bit[0] = 2;
	bit[1] = 2;
	bit[2] = 2;
	bit[3] = 2;
	if (a < 128)
	{
		ft_putchar(a);
		env->nb_char++;
	}
	else if (a < 2048)
	{
		bit[1] = 6;
		ft_replacebit(bit, a, 11, env);
	}
	else if (a < 65536)
	{
		bit[2] = 14;
		ft_replacebit(bit, a, 16, env);
	}
	else if (a < 2097152)
	{
		bit[3] = 30;
		ft_replacebit(bit, a, 21, env);
	}
	ft_putchar(bit[3]);
	ft_putchar(bit[2]);
	ft_putchar(bit[1]);
	ft_putchar(bit[0]);
}

void			ft_space_str(char *str, t_env *env)
{
	if (env->flag_sp == 1)
	{
		ft_putchar(' ');
		env->nb_char++;
		(env->nb_sp > 0) ? env->nb_sp-- : 0;
	}
	if (env->flag_ms == 1)
	{
		flag_dz_str(env, str);
		flag_pt_xo(env, str);
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
		flag_pt_xo(env, str);
		if (env->flag_pt != -1 || ft_strcmp(str, "0") != 0)
			ft_putstr(str);
		else
			env->nb_char--;
	}
	else if (env->flag_ms == 0 && env->nb_sp > env->flag_pt &&
			env->flag_pt != 0)
	{
		ft_putarg_str(env, str);
		flag_pt_xo(env, str);
		flag_dz_str(env, str);
		if (env->flag_pt != -1 || ft_strcmp(str, "0") != 0)
			ft_putstr(str);
		else
			env->nb_char--;
	}
	else
	{
		flag_dz_str(env, str);
		flag_pt_xo(env, str);
		ft_putarg_str(env, str);
		if (env->flag_pt != -1 || ft_strcmp(str, "0") != 0)
			ft_putstr(str);
		else
			env->nb_char--;
	}
}

void			ft_space_int(long long a, t_env *env)
{
	int			i;

	i = 0;
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
		if (((env->flag_ll == 1 || env->flag_l == 1) && env->conv == 'u') || env->conv == 'U')
			ft_putnbr_ull(a);
		else if ((env->conv == 'D' || env->flag_z == 1) && a < 0 && a > -2147483648)
			ft_putnbr_ui(a);
		else
			ft_putnbr_ll(a);
	}
	else if (env->flag_zr == 1 && (env->flag_ps == 1 || a < 0))
	{
		(a < 0) ? ft_putchar('-') : ft_putchar('+');
		ft_putarg_ll(env, a);
		(a < 0) ? a *= -1 : 0;
		if (((env->flag_ll == 1 || env->flag_l == 1) && env->conv == 'u') || env->conv == 'U')
			ft_putnbr_ull(a);
		else if ((env->conv == 'D' || env->flag_z == 1) && a < 0 && a > -2147483648)
			ft_putnbr_ui(a);
		else
			ft_putnbr_ll(a);
	}
	else if (env->flag_ms == 1)
	{
		(env->flag_ps == 1 && a >= 0) ? ft_putchar('+') : 0;
		if (((env->flag_ll == 1 || env->flag_l == 1) && env->conv == 'u') || env->conv == 'U')
			ft_putnbr_ull(a);
		else if ((env->conv == 'D' || env->flag_z == 1) && a < 0 && a > -2147483648)
			ft_putnbr_ui(a);
		else
			ft_putnbr_ll(a);
		ft_putarg_ll(env, a);
	}
	else
	{
		ft_putarg_ll(env, a);
		(env->flag_ps == 1 && a >= 0) ? ft_putchar('+') : 0;
		if (env->flag_pt != -1 || a != 0)
		{
			if (((env->flag_ll == 1 || env->flag_l == 1) && env->conv == 'u') || env->conv == 'U')
				ft_putnbr_ull(a);
			else if (((env->conv == 'D' && env->flag_d == 0) || env->flag_z == 1) && a < 0 && a > -2147483648)
				ft_putnbr_ui(a);
			else
				ft_putnbr_ll(a);
		}
		else
			env->nb_char--;
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
			(env->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
			i++;
			env->nb_char++;
		}
	}
	else
	{
		while (i < env->nb_sp - 1)
		{
			(env->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
			i++;
			env->nb_char++;
		}
		ft_putchar(c);
	}
	env->nb_char++;
}
