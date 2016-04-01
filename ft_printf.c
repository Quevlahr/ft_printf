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

static t_arg		*ft_argnew(t_help tmp)
{
	t_arg		*new_arg;

	if (!(new_arg = (t_arg*)malloc(sizeof(t_arg))))
		ft_error(NULL);
	new_arg->next = NULL;
	new_arg->prev = NULL;
	return (new_arg);
}

static void			ft_argpush(t_arg **arg)
{
	t_arg		*tmp_arg;
	t_arg		*prev_arg;

	tmp_arg = *arg;
	if (tmp_arg)
	{
		while (tmp_arg->next)
			tmp_arg = tmp_arg->next;
		prev_arg = tmp_arg;
		tmp_arg->next = ft_argnew(tmp);
		tmp_arg = tmp_arg->next;
		tmp_arg->prev = prev_arg;
	}
	else
		*arg = ft_argnew(tmp);
}

void				ft_read(char *format, int i, t_env env, t_arg arg)
{
	env.nb_arg = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			env.nb_arg++;
			ft_argpush(arg);
		}
		i++;
	}
}

int					ft_printf(const char *format, ...)
{
	va_list			ap;
	t_arg			*arg;
	t_env			env;
	// char			*str;

	arg = (t_arg*)malloc(sizoef(t_arg));
	env.arg = arg;
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
