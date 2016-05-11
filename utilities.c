/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:14:46 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/11 18:43:56 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_error(t_env *env)
{
	if (env == NULL)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_FAILURE);
}

void			ft_print_env(t_env *env)
{
	ft_putstr("flag l = ");
	ft_putnbrdl(env->flag_l);
	ft_putstr("flag ll = ");
	ft_putnbrdl(env->flag_ll);
	ft_putstr("flag h = ");
	ft_putnbrdl(env->flag_h);
	ft_putstr("flag hh = ");
	ft_putnbrdl(env->flag_hh);
	ft_putstr("flag j = ");
	ft_putnbrdl(env->flag_j);
	ft_putstr("flag z = ");
	ft_putnbrdl(env->flag_z);
	ft_putstr("flag . = ");
	ft_putnbrdl(env->flag_pt);
	ft_putstr("flag # = ");
	ft_putnbrdl(env->flag_dz);
	ft_putstr("flag 0 = ");
	ft_putnbrdl(env->flag_zr);
	ft_putstr("flag - = ");
	ft_putnbrdl(env->flag_ms);
	ft_putstr("flag + = ");
	ft_putnbrdl(env->flag_ps);
	ft_putstr("flag ' ' = ");
	ft_putnbrdl(env->flag_sp);
	ft_putstr("nb ' ' = ");
	ft_putnbrdl(env->nb_sp);
	ft_putstr("nb arg = ");
	ft_putnbrdl(env->nb_arg);
	ft_putstr("nb char = ");
	ft_putnbrdl(env->nb_char);
	ft_putstr("conversion = ");
	ft_putchar(env->conv);
	ft_putchar('\n');
	ft_putchar('\n');
}
