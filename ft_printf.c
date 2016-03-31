/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:37:04 by quroulon          #+#    #+#             */
/*   Updated: 2016/03/31 15:37:18 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_read(va_list ap, t_env *env)
{
	t_arg			*args;

	args = env->args;
	while (va_arg(ap, ))
}

int					ft_printf(const char *format, ...)
{
	va_list			ap;
	t_arg			*args;
	t_env			env;
	// char			*str;

	args = (t_args*)malloc(sizoef(t_arg));
	env.args = args;
	va_start(ap, format);
	ft_read(ap, &env);
	// str = va_arg(ap, char *);
	// str = va_arg(ap, char *);
	// while (*format && *format != '%')
	// {
	// 	ft_putchar(*format);
	// 	format++;
	// }
	// ft_putendl(str);
	return (1);
}
