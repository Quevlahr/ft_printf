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

void				ft_read(const char *format, int i, t_env env, t_arg *arg)
{
	int				j;
	t_help			help;

	env.nb_arg = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			j = i;
			ft_initflag(format, &help, &j);
			if (format[j] && (format[j] == 's' || format[j] == 'S' || 
				format[j] == 'p' || format[j] == 'D' || format[j] == 'i' ||
				format[j] == 'o' || format[j] == 'O' || format[j] == 'u' ||
				format[j] == 'U' || format[j] == 'x' || format[j] == 'X' ||
				format[j] == 'c' || format[j] == 'C')) // manque h hh l ll j z
			{
				env.nb_arg++;
				arg->conv = format[j];
				ft_argpush(&arg, help);
				j++;
			}
			i = j;
		}
		else if (format[i])
			ft_putchar(format[i]);
		i++;
	}
	if (env.nb_arg != 0)
		ft_initlstend(&arg);
}

int					ft_printf(const char *format, ...)
{
	va_list			ap;
	t_arg			*arg;
	t_env			env;
	// char			*str;

	arg = (t_arg*)malloc(sizeof(t_arg));
	env.arg = *arg;
	va_start(ap, format);
	ft_read(format, 0, env, arg);
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
