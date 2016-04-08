/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:14:46 by quroulon          #+#    #+#             */
/*   Updated: 2016/04/04 14:14:48 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_error(t_env *env)
{
	if (env == NULL)
	{
		ft_putendl("Error");
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_putendl("Error");
		exit(EXIT_FAILURE);
	}
}

void			ft_print_details(t_arg *arg)
{
	arg = arg->start;
	while (arg->next)
	{
		ft_putstr("Conversion = ");
		ft_putchar(arg->conv);
		ft_putendl(" : ");
		arg->flag_dz == 1 ? ft_putendl("flag_dz"): 0;
		arg->flag_zr == 1 ? ft_putendl("flag_zr"): 0;
		arg->flag_ms == 1 ? ft_putendl("flag_ms"): 0;
		arg->flag_ps == 1 ? ft_putendl("flag_ps"): 0;
		arg->flag_sp == 1 ? ft_putendl("flag_sp"): 0;
		ft_putchar('\n');
		arg = arg->next;
	}
}
