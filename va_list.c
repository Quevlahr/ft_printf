/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 21:19:59 by quroulon          #+#    #+#             */
/*   Updated: 2016/04/08 21:20:03 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			flag_int(int a, t_env *env, va_list ap)
{
	a = va_arg(ap, int);
	ft_putnbr(a);
	env->nb_char += ft_nbrlen(a);
}

void			flag_str(char *a, t_env *env, va_list ap)
{
	a = va_arg(ap, char*);
	ft_putstr(a);
	env->nb_char += ft_strlen(a);

}

void			ft_useva(t_env *env, va_list ap, t_help *help)
{
	(help->conv == '\0') ? ft_error(NULL) : 0;
	(help->conv == 'd') ? flag_int(0, env, ap) : 0;
	(help->conv == 's') ? flag_str(NULL, env, ap) : 0;
	(help->nb_sp != 0) ? flag_digit();
}
