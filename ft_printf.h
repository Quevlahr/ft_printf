/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:19:17 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/11 18:44:16 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <locale.h>
# include <limits.h>

typedef struct		s_env
{
	int				flag_l;
	int				flag_ll;
	int				flag_h;
	int				flag_hh;
	int				flag_j;
	int				flag_z;
	int				flag_pt;

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

/*
**	ft_printf.c
*/
int					ft_printf(const char *format, ...);

/*
**	utilities.c
*/
void				ft_error(t_env *env);
void				ft_print_env(t_env *env);

/*
**	flags.c
*/
void				ft_initflag(const char *format, t_env *env, int *j);
void				ft_initconv(int *i, t_env *env, va_list ap);

/*
**	va_list.c
*/
void				ft_useva(t_env *env, va_list ap);

/*
**	ft_space.c
*/
void				ft_space_int(long long a, t_env *env);
void				ft_space_str(char *str, t_env *env);
void				ft_space_char(char c, t_env *env);

/*
**	ft_forstr.c
*/
void				ft_null_str(t_env *env);
char				*ft_modifstr(char *str, t_env *env);

/*
**	flags_application.c
*/
void				flag_dz_str(t_env *env, char *str);
void				ft_putarg_str(t_env *env, char *str);
void				ft_putarg_ll(t_env *env, long long a);

void				flag_pt_xo(t_env *env, char *str);

/*
**	ft_init.c
*/
void				ft_initenv(t_env *env);
void				ft_initdigit(t_env *env, int *i);
int					ft_verifbase(t_env *env, int *i);
void				ft_veriflh(t_env *env, int *i, int *tmpl, int *tmph);
int					ft_verifchar(char c);

/*
** ft_gestion.c
*/
void				ft_maxtype(t_env *e);


/*
**	libft
*/
void				ft_putnbr_ull(unsigned long long nb);
void				ft_putnbr_ul(unsigned long nb);
void				ft_putnbr_ui(unsigned int nb);
void				ft_putnbr_ll(long long nb);
void				ft_putnbr_l(long nb);

int					ft_nbrlen_ull(unsigned long long n);
int					ft_nbrlen_ul(unsigned long n);
int					ft_nbrlen_ui(unsigned int n);
int					ft_nbrlen_ll(long long n);
int					ft_nbrlen_l(long n);

char				*ft_itoabase_ull(unsigned long long n, int base, int maj);
char				*ft_itoabase_ui(unsigned int n, int base, int maj);

#endif
