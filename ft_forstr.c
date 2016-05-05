/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:34:00 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/05 16:35:29 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_null_str(t_env *env)
{
	ft_putstr("(null)");
	env->nb_char += 6;
}

char			*ft_modifstr(char *str, t_env *env)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = ft_strnew(ft_strlen(str));
	while (str[i] && i < env->flag_pt)
	{
		tmp[i] = str[i];
		i++;
	}
	return (tmp);
}
