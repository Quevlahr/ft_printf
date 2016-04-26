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

void			ft_space_str(char *str, t_env *env, int tmp)
{
	if (ft_strlen(str) >= env->nb_sp)
	{
		ft_putstr(str);
		env->nb_char += ft_strlen(str);
	}
	else if (env->flag_ms == 0 && env->flag_zr == 1)
	{
		tmp = ft_strlen(str);
		while (tmp < env->nb_sp)
		{
			ft_putchar('0');
			tmp++;
			env->nb_char++;
		}
		ft_putstr(str);
		env->nb_char += ft_strlen(str);
	}
	else if (env->flag_ms == 1)
	{
		ft_putstr(str);
		env->nb_char += ft_strlen(str);
		tmp = ft_strlen(str);
		while (tmp < env->nb_sp)
		{
			ft_putchar(' ');
			tmp++;
			env->nb_char++;
		}
	}
	else
	{
		while (tmp < (env->nb_sp - ft_strlen(str)))
		{
			ft_putchar(' ');
			tmp++;
			env->nb_char++;
		}
		ft_putstr(str);
		env->nb_char += ft_strlen(str);
	}
}

void			ft_space_int(int a, t_env *env, int tmp)
{
	if (ft_nbrlen(a) >= env->nb_sp)
	{
		ft_putnbr(a);
		env->nb_char += ft_nbrlen(a);
	}
	else if (env->flag_ms == 0 && env->flag_zr == 1)
	{
		tmp = ft_nbrlen(a);
		while (tmp < env->nb_sp)
		{
			ft_putchar('0');
			tmp++;
			env->nb_char++;
		}
		ft_putnbr(a);
		env->nb_char += ft_nbrlen(a);
	}
	else if (env->flag_ms == 1)
	{
		ft_putnbr(a);
		env->nb_char += ft_nbrlen(a);
		tmp = ft_nbrlen(a);
		while (tmp < env->nb_sp)
		{
			ft_putchar(' ');
			tmp++;
			env->nb_char++;
		}
	}
	else
	{
		while (tmp < (env->nb_sp - ft_nbrlen(a)))
		{
			ft_putchar(' ');
			tmp++;
			env->nb_char++;
		}
		ft_putnbr(a);
		env->nb_char += ft_nbrlen(a);
	}
}

void			ft_space_ll(long long a, t_env *env, int tmp)
{
	if (ft_nbrlen_ll(a) >= env->nb_sp)
	{
		ft_putnbr_ll(a);
		env->nb_char += ft_nbrlen_ll(a);
	}
	else if (env->flag_ms == 0 && env->flag_zr == 1)
	{
		tmp = ft_nbrlen_ll(a);
		while (tmp < env->nb_sp)
		{
			ft_putchar('0');
			tmp++;
			env->nb_char++;
		}
		ft_putnbr_ll(a);
		env->nb_char += ft_nbrlen_ll(a);
	}
	else if (env->flag_ms == 1)
	{
		ft_putnbr_ll(a);
		env->nb_char += ft_nbrlen_ll(a);
		tmp = ft_nbrlen_ll(a);
		while (tmp < env->nb_sp)
		{
			ft_putchar(' ');
			tmp++;
			env->nb_char++;
		}
	}
	else
	{
		while (tmp < (env->nb_sp - ft_nbrlen_ll(a)))
		{
			ft_putchar(' ');
			tmp++;
			env->nb_char++;
		}
		ft_putnbr_ll(a);
		env->nb_char += ft_nbrlen_ll(a);
	}
}

void			ft_space_long(long a, t_env *env, int tmp)
{
	if (ft_nbrlen_l(a) >= env->nb_sp)
	{
		ft_putnbr_l(a);
		env->nb_char += ft_nbrlen_l(a);
	}
	else if (env->flag_ms == 0 && env->flag_zr == 1)
	{
		tmp = ft_nbrlen_l(a);
		while (tmp < env->nb_sp)
		{
			ft_putchar('0');
			tmp++;
			env->nb_char++;
		}
		ft_putnbr_l(a);
		env->nb_char += ft_nbrlen_l(a);
	}
	else if (env->flag_ms == 1)
	{
		ft_putnbr_l(a);
		env->nb_char += ft_nbrlen_l(a);
		tmp = ft_nbrlen_l(a);
		while (tmp < env->nb_sp)
		{
			ft_putchar(' ');
			tmp++;
			env->nb_char++;
		}
	}
	else
	{
		while (tmp < (env->nb_sp - ft_nbrlen_l(a)))
		{
			ft_putchar(' ');
			tmp++;
			env->nb_char++;
		}
		ft_putnbr_l(a);
		env->nb_char += ft_nbrlen_l(a);
	}
}
