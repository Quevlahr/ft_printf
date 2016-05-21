/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:34:00 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/21 20:24:25 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_null_str(char **str, t_env *env)
{
	*str = ft_strnew(7);
	*str = ft_strcpy(*str, "(null)");
}

void			ft_null_wstr(wchar_t **str, t_env *env)
{
	*str = (wchar_t*)malloc(sizeof(wchar_t) * 7);
	(*str)[0] = '(';
	(*str)[1] = 'n';
	(*str)[2] = 'u';
	(*str)[3] = 'l';
	(*str)[4] = 'l';
	(*str)[5] = ')';
	(*str)[6] = '\0';
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
