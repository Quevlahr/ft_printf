/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:19:17 by quroulon          #+#    #+#             */
/*   Updated: 2016/03/31 15:19:18 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

typedef struct 		s_help
{
	int				flag_dz;
	int				flag_zr;
	int				flag_ms;
	int				flag_ps;
	int				flag_sp;
	char			conv;
}					t_help;

typedef struct		s_env
{
	int				nb_arg;
	int				nb_char;
	const char		*str;
}					t_env;

int					ft_printf(const char *format, ...);

void				ft_error(t_env *env);

void				ft_initflag(const char *format, t_help *help, int *j);
void				ft_initconv(t_help *help, int *i, t_env *env, va_list ap);

void				ft_useva(t_env *env, va_list ap, t_help *help);

#endif
