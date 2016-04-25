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
#include <locale.h>

typedef struct		s_env
{
	int				flag_dz;
	int				flag_zr;
	int				flag_ms;
	int				flag_ps;
	int				flag_sp;
	int				nb_sp;
	char			conv;

	int				nb_arg;
	int				nb_char;
	const char		*str;
}					t_env;

int					ft_printf(const char *format, ...);

void				ft_error(t_env *env);
void				ft_print_env(t_env *env);

void				ft_initdigit(const char *format, t_env *env, int *i);
void				ft_initflag(const char *format, t_env *env, int *j);
void				ft_initconv(int *i, t_env *env, va_list ap);

void				ft_useva(t_env *env, va_list ap);

void				ft_space_int(int a, t_env *env, int tmp);
void				ft_space_str(char *str, t_env *env, int tmp);

#endif
