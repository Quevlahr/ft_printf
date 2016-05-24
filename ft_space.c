/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:24:40 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/24 12:11:05 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

UI				ft_givebit(UI pos, UI n)
{
	return (((1 << pos) & n) >> pos);
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
	return (seis);
}

void			ft_space_wchar(int a, t_env *env)
{
	UI			bit[4];
	int			seis;

	bit[0] = 2;
	bit[1] = 2;
	bit[2] = 2;
	bit[3] = 2;
	seis = 0;
	if (a < 128)
	{
		ft_putchar(a);
		env->nb_char++;
	}
	else if (a < 2048)
	{
		bit[1] = 6;
		seis = ft_replacebit(bit, a, 11, env);
	}
	else if (a < 65536)
	{
		bit[2] = 14;
		seis = ft_replacebit(bit, a, 16, env);
	}
	else if (a < 2097152)
	{
		bit[3] = 30;
		seis = ft_replacebit(bit, a, 21, env);
	}
	while (seis > 0)
	{
		ft_putchar(bit[seis - 1]);
		seis--;
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
