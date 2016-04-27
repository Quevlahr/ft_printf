/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_application.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:33:00 by quroulon          #+#    #+#             */
/*   Updated: 2016/04/26 17:33:02 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			flag_dz_str(t_env *env, char *str)
{
	if (env->flag_dz == 1 && ft_strcmp(str, "0") != 0)
	{
		(env->maj == 1) ? ft_putstr("0X") : ft_putstr("0x");
		env->nb_char += 2;
	}
}

void			ft_putarg_str(t_env *env, char *str)
{
	int			i;
	int			diese;

	i = 0;
	diese = (env->flag_dz == 1) ? 2 : 0;
	if (ft_strlen(str) + diese < env->nb_sp)
		while (i < (env->nb_sp - (ft_strlen(str) + diese)))
		{
			(env->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
			i++;
			env->nb_char++;
		}
	env->nb_char += ft_strlen(str);
}

void			ft_putarg_int(t_env *env, int a)
{
	int			i;
	int			diese;

	i = 0;
	diese = (env->flag_dz == 1) ? 2 : 0;
	if (ft_nbrlen(a) + diese < env->nb_sp)
		while (i < (env->nb_sp - (ft_nbrlen(a) + diese)))
		{
			(env->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
			i++;
			env->nb_char++;
		}
	env->nb_char += ft_nbrlen(a);
}

void			ft_putarg_long(t_env *env, long a)
{
	int			i;
	int			diese;

	i = 0;
	diese = (env->flag_dz == 1) ? 2 : 0;
	if (ft_nbrlen_l(a) + diese < env->nb_sp)
		while (i < (env->nb_sp - (ft_nbrlen_l(a) + diese)))
		{
			(env->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
			i++;
			env->nb_char++;
		}
	env->nb_char += ft_nbrlen_l(a);
}

void			ft_putarg_ll(t_env *env, long long a)
{
	int			i;
	int			diese;

	i = 0;
	diese = (env->flag_dz == 1) ? 2 : 0;
	if (ft_nbrlen_ll(a) + diese < env->nb_sp)
		while (i < (env->nb_sp - (ft_nbrlen_ll(a) + diese)))
		{
			(env->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
			i++;
			env->nb_char++;
		}
	env->nb_char += ft_nbrlen_ll(a);
}
