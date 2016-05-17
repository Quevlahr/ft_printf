/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_application.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:33:00 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/17 20:25:35 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			flag_dz_str(t_env *env, char *str)
{
	if (env->flag_dz == 1 && env->conv == 'p')
	{
		(env->maj == 1) ? ft_putstr("0X") : ft_putstr("0x");
		env->nb_char += 2;
	}
	else if (env->flag_dz == 1 && ft_strcmp(str, "0") != 0 && env->conv != 'o' && env->conv != 'O')
	{
		(env->maj == 1) ? ft_putstr("0X") : ft_putstr("0x");
		env->nb_char += 2;
	}
}

void			ft_putarg_wstr(t_env *env, wchar_t *str)
{
	int			i;
	int			surplus;

	i = 0;
	surplus = (env->flag_dz == 1) ? 2 : 0;
	if ((int)ft_wstrlen(str) + surplus < env->nb_sp)
	{
		while (i < (env->nb_sp - ((int)ft_wstrlen(str) + surplus)))
		{
			if (env->flag_pt != 0)
				(env->flag_zr == 1 && env->nb_sp < env->flag_pt) ?
				ft_putchar('0') : ft_putchar(' ');
			else
				(env->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
			i++;
			env->nb_char++;
		}
	}
}

void			ft_putarg_str(t_env *env, char *str)
{
	int			i;
	int			surplus;

	i = 0;
	surplus = 0;
	if (env->conv == 'o')
		surplus -= (ft_strcmp(str, "0") == 0 && env->flag_pt == -1) ? 1 : 0;
	else
		surplus = (env->flag_dz == 1) ? 2 : 0;
	if (env->conv == 'o' || env->conv == 'x')
		surplus += (env->flag_pt > 0 && env->flag_pt > (int)ft_strlen(str)) ?
					env->flag_pt - ft_strlen(str) : 0;
	if ((int)ft_strlen(str) + surplus < env->nb_sp)
	{
		while (i < (env->nb_sp - ((int)ft_strlen(str) + surplus)))
		{
			if (env->flag_pt != 0)
				(env->flag_zr == 1 && env->nb_sp < env->flag_pt) ?
				ft_putchar('0') : ft_putchar(' ');
			else
				(env->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
			i++;
			env->nb_char++;
		}
	}
	env->nb_char += ft_strlen(str);
}

void			ft_putarg_ll(t_env *env, long long a)
{
	int			i;
	int			surplus;

	i = 0;
	surplus = (env->flag_dz == 1) ? 2 : 0;
	surplus += (a < 0 || (env->flag_ps == 1 && a >= 0)) ? 1 : 0;
	surplus += (env->flag_pt > 0 && env->flag_pt > ft_nbrlen_ll(a)) ?
				env->flag_pt - ft_nbrlen_ll(a) : 0;
	surplus += (env->flag_ps == -1) ? 1 : 0;
	surplus -= (a == 0 && env->flag_pt == -1) ? 1 : 0;
	if (ft_nbrlen_ll(a) + surplus < env->nb_sp)
		while (i < (env->nb_sp - (ft_nbrlen_ll(a) + surplus)))
		{
			if (env->flag_pt > 0)
				(env->flag_zr == 1 && env->nb_sp < (env->flag_pt - 1)) ?
					ft_putchar('0') : ft_putchar(' ');
			else
				(env->flag_zr == 1 && env->flag_pt != -1) ? ft_putchar('0') : ft_putchar(' ');
			i++;
			env->nb_char++;
		}
	i = 0;
	if ((env->flag_ps == 1 || a < 0) && env->flag_pt > 0)
		(a < 0) ? ft_putchar('-') : ft_putchar('+');
	if (env->flag_ms == 0)
		while (i < (env->flag_pt - ft_nbrlen_ll(a)))
		{
			ft_putchar('0');
			i++;
			env->nb_char++;
		}
	if ((env->flag_l == 1 && env->conv == 'u') || env->conv == 'U')
		env->nb_char += ft_nbrlen_ull(a);
	else if (env->flag_z == 1 && a < 0 && a > -2147483648)
		env->nb_char += ft_nbrlen_ui(a);
	else
		env->nb_char += ft_nbrlen_ll(a);
}
