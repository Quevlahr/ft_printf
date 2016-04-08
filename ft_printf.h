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

typedef struct		s_arg
{
	int				flag_dz;
	int				flag_zr;
	int				flag_ms;
	int				flag_ps;
	int				flag_sp;
	char			conv;
	struct s_arg	*next;
	struct s_arg	*prev;
	struct s_arg	*start;
	struct s_arg	*end;
}					t_arg;

typedef struct		s_env
{
	char			*str;
	int				nb_arg;
	int				nb_char;
	struct s_arg	*arg;
}					t_env;

int					ft_printf(const char *format, ...);

void				ft_error(t_env *env);
void				ft_print_details(t_arg *arg);

void				ft_initlstend(t_arg **arg);
t_arg				*ft_argnew(t_help help);
void				ft_argpush(t_arg **arg, t_help help);

void				ft_initflag(const char *format, t_help *help, int *j);
void				ft_initlastarg(t_help *help);

void			ft_useva(t_arg *arg, t_env env, va_list ap);

#endif
