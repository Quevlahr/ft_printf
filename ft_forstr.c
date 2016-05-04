/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:34:00 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/04 16:11:08 by quroulon         ###   ########.fr       */
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

char			*ft_modifhexa(char *str, t_env *env)
{
	int			i;
	int			j;
	char		*tmp;

	i = 0;
	j = 0;
	tmp = ft_strnew(17);
	while (i < 16 - ft_strlen(str))
	{
		if (i < 8)
			tmp[i] = (env->maj == 0) ? 'f' : 'F';
		else
			tmp[i] = '0';
		i++;
	}
	while (str[j])
	{
		tmp[i] = str[j];
		i++;
		j++;
	}
	return (tmp);
}
