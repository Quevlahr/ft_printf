/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_application2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 19:24:14 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/06 19:37:45 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			flag_pt_xo(t_env *env, char *str)
{
	int			i;

	i = 0;
	if (env->flag_pt > 0 && env->conv != 's')
	{
		(env->flag_dz == 1) ? i++ : 0;
		while (i < (env->flag_pt - (int)ft_strlen(str)))
		{
			ft_putchar('a');
			i++;
			env->nb_char++;
		}
	}
}
