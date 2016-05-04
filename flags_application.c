/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_application.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:33:00 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/04 15:57:24 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			flag_dz_str(t_env *env, char *str)
{
	if (env->flag_dz == 1 && ft_strcmp(str, "0") != 0 && env->conv != 'o')
	{
		(env->maj == 1) ? ft_putstr("0X") : ft_putstr("0x");
		env->nb_char += 2;
	}
	else if (env->flag_dz == 1 && env->conv == 'o')
	{
		ft_putchar('0');
		env->nb_char++;
	}
}

void			ft_putarg_str(t_env *env, char *str)
{
	int			i;
	int			surplus;

	i = 0;
	if (env->conv == 'o')
	{
		surplus = (env->flag_dz == 1) ? 1 : 0;
		surplus += (env->flag_pt > 0 && env->flag_pt > ft_strlen(str)) ?
					env->flag_pt - ft_strlen(str) : 0;
		surplus -= (ft_strcmp(str, "0") == 0 && env->flag_pt == -1) ? 1 : 0;
	}
	else
		surplus = (env->flag_dz == 1) ? 2 : 0;
	if (ft_strlen(str) + surplus < env->nb_sp)
	{
		while (i < (env->nb_sp - (ft_strlen(str) + surplus)))// && env->flag_pt)
		{
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
				(env->flag_zr == 1 && env->nb_sp < (env->flag_pt - 1)) ? ft_putchar('0') : ft_putchar(' ');
			else
				(env->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
			i++;
			env->nb_char++;
		}
	i = 0;
	if ((env->flag_ps == 1 || a < 0) && env->flag_pt > 0)
		(a < 0) ? ft_putchar('-') : ft_putchar('+');
	if (env->flag_ms == 0)
		while (i < (env->flag_pt - ft_nbrlen(a)))
		{
			ft_putchar('0');
			i++;
			env->nb_char++;
		}
	env->nb_char += ft_nbrlen_ll(a);
}