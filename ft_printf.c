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

void				ft_read(const char *format, int i, t_env *env, va_list ap)
{
	t_help			help;

	env->nb_arg = 0;
	env->nb_char = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0' && format[i + 1] != '%')
		{
			i++;
			ft_initflag(format, &help, &i);
			ft_initconv(&help, &i, env, ap);
		}
		else if (format[i])
		{
			// (format[i] == 'y') ? ft_putendl("ICITAMERE") : 0;
			if (ft_strcmp(format + i, "yoloswag") == 0)
			{
				ft_putendl("format :");
				ft_putendl(format);
				ft_putchar('\n');
				ft_putendl("fin format");
			}
			(format[i] == '%') ? i++ : 0;
			env->nb_char++;
			ft_putchar(format[i]);
			i++;
		}
	}
}

int					ft_printf(const char *format, ...)
{
	va_list			ap;
	t_env			env;

	va_start(ap, format);
	env.str = format;
	ft_read(format, 0, &env, ap);
	return (env.nb_char);
}
