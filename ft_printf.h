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
	int				flag_l;
	int				flag_ll;
	int				flag_h;
	int				flag_hh;
	int				flag_j;
	int				flag_z;

	int				flag_dz;
	int				flag_zr;
	int				flag_ms;
	int				flag_ps;
	int				flag_sp;

	int				maj;
	int				nb_sp;
	char			conv;
	int				nb_char;
	int				nb_arg;
	const char		*str;
}					t_env;

int					ft_printf(const char *format, ...);

void				ft_error(t_env *env);
void				ft_print_env(t_env *env);

void				ft_initdigit(const char *format, t_env *env, int *i);
void				ft_initflag(const char *format, t_env *env, int *j);
void				ft_initconv(int *i, t_env *env, va_list ap);

void				ft_useva(t_env *env, va_list ap);

void				ft_space_int(int a, t_env *env);
void				ft_space_str(char *str, t_env *env);
void				ft_space_ll(long long a, t_env *env);
void				ft_space_long(long a, t_env *env);

void				ft_null_str(t_env *env);

void				flag_dz_str(t_env *env, char *str);
void				ft_putarg_str(t_env *env, char *str);
void				ft_putarg_int(t_env *env, int a);
void				ft_putarg_long(t_env *env, long a);
void				ft_putarg_ll(t_env *env, long long a);


void				ft_putnbr_ll(long long nb);
int					ft_nbrlen_ll(long long n);

void				ft_putnbr_l(long nb);
int					ft_nbrlen_l(long n);

char				*ft_itoabase_ull(unsigned long long n, int base, int maj);

#endif
