/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:24:40 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/13 22:00:47 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int			ft_verif(char *str, int *i, int sign)
// {
// 	while (str[*i] == ' ' || str[*i] == '\n' || str[*i] == '\t' ||
// 			str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
// 		(*i)++;
// 	if (str[*i] == '-')
// 		sign = -1;
// 	else if (str[*i] == '+')
// 		sign = 1;
// 	return (sign);
// }

// static long			ft_atoibase(char *str, int base)
// {
// 	int				i;
// 	long			res;
// 	int				sign;

// 	i = 0;
// 	res = 0;
// 	sign = ft_verif(str, &i, 1);
// 	while (ft_isdigit(str[i]) == 1 || (str[i] <= 'f' && str[i] >= 'a') ||
// 			(str[i] <= 'F' && str[i] >= 'A'))
// 	{
// 		if (str[i] == '\0')
// 			return (res);
// 		res *= base;
// 		if (ft_isdigit(str[i]) == 1)
// 			res += (str[i] - '0') * base;
// 		else if (str[i] <= 'f' && str[i] >= 'a')
// 			res += (str[i] - 'a' + 10) * base;
// 		else if (str[i] <= 'F' && str[i] >= 'A')
// 			res += (str[i] - 'A' + 10) * base;
// 		i++;
// 	}
// 	return (sign * (res /= base));
// }


// void			ft_space_wchar(char *str, t_env *env)
// {
// 	int			i;
// 	int			max;
// 	int			*tab;

// 	i = 0;
// 	max = ft_strlen(str);
// 	tab = (int*)malloc(sizeof (int) * 4);
// 	i = ft_atoibase(str, 2);
// 	ft_putnbrdl(i);
// 	if (ft_strlen(str) <= 7)
// 	{
// 		tab[0] = ft_atoibase(str, 2);
// 		ft_putchar(&tab[0]);
// 	}
// 	else if (ft_strlen(str) <= 11)
// 	{
// 		while (i < ft_strlen(str))
// 		{
// 			if (str[max] == '0')
// 				int[0] = 
// 			i++;
// 			max--;
// 		}
// 	}
// 	else if (ft_strlen(str) <= 16)
// 	{
	
// 	}
// 	else
// 	{

// 	}
// }

void			ft_space_str(char *str, t_env *env)
{
	if (env->flag_sp == 1)
	{
		ft_putchar(' ');
		env->nb_char++;
		(env->nb_sp > 0) ? env->nb_sp-- : 0;
	}
	if (env->flag_ms == 1)
	{
		flag_dz_str(env, str);
		flag_pt_xo(env, str);
		if (env->flag_pt != -1 || ft_strcmp(str, "0") != 0)
			ft_putstr(str);
		else
			env->nb_char--;
		ft_putarg_str(env, str);
	}
	else if (env->flag_dz == 1 && env->flag_zr == 0)
	{
		ft_putarg_str(env, str);
		flag_dz_str(env, str);
		flag_pt_xo(env, str);
		if (env->flag_pt != -1 || ft_strcmp(str, "0") != 0)
			ft_putstr(str);
		else
			env->nb_char--;
	}
	else if (env->flag_ms == 0 && env->nb_sp > env->flag_pt &&
			env->flag_pt != 0)
	{
		ft_putarg_str(env, str);
		flag_pt_xo(env, str);
		flag_dz_str(env, str);
		if (env->flag_pt != -1 || ft_strcmp(str, "0") != 0)
			ft_putstr(str);
		else
			env->nb_char--;
	}
	else
	{
		flag_dz_str(env, str);
		flag_pt_xo(env, str);
		ft_putarg_str(env, str);
		if (env->flag_pt != -1 || ft_strcmp(str, "0") != 0)
			ft_putstr(str);
		else
			env->nb_char--;
	}
}

void			ft_space_int(long long a, t_env *env)
{
	int			i;

	i = 0;
	if (env->flag_ms == 1)
	{
		if (a < 0 || env->flag_ps == 1)
		{
			(a < 0) ? ft_putchar('-') : ft_putchar('+');
			(a < 0) ? a *= -1 : 0;
			env->flag_ps = -1;
			env->nb_char++;
		}
		while (i < (env->flag_pt - ft_nbrlen(a)))
		{
			ft_putchar('0');
			i++;
			env->nb_char++;
		}
	}
	if (env->flag_sp == 1 && env->flag_ps == 0 && a > 0)
	{
		ft_putchar(' ');
		env->nb_char++;
		(env->nb_sp > 0) ? env->nb_sp-- : 0;
	}
	if ((env->flag_ps == 1 || a < 0) && env->flag_pt > 0)
	{
		ft_putarg_ll(env, a);
		a *= (a < 0) ? -1 : 1;
		if (((env->flag_ll == 1 || env->flag_l == 1) && env->conv == 'u') || env->conv == 'U')
			ft_putnbr_ull(a);
		else if ((env->conv == 'D' || env->flag_z == 1) && a < 0 && a > -2147483648)
			ft_putnbr_ui(a);
		else
			ft_putnbr_ll(a);
	}
	else if (env->flag_zr == 1 && (env->flag_ps == 1 || a < 0))
	{
		(a < 0) ? ft_putchar('-') : ft_putchar('+');
		ft_putarg_ll(env, a);
		(a < 0) ? a *= -1 : 0;
		if (((env->flag_ll == 1 || env->flag_l == 1) && env->conv == 'u') || env->conv == 'U')
			ft_putnbr_ull(a);
		else if ((env->conv == 'D' || env->flag_z == 1) && a < 0 && a > -2147483648)
			ft_putnbr_ui(a);
		else
			ft_putnbr_ll(a);
	}
	else if (env->flag_ms == 1)
	{
		(env->flag_ps == 1 && a >= 0) ? ft_putchar('+') : 0;
		if (((env->flag_ll == 1 || env->flag_l == 1) && env->conv == 'u') || env->conv == 'U')
			ft_putnbr_ull(a);
		else if ((env->conv == 'D' || env->flag_z == 1) && a < 0 && a > -2147483648)
			ft_putnbr_ui(a);
		else
			ft_putnbr_ll(a);
		ft_putarg_ll(env, a);
	}
	else
	{
		ft_putarg_ll(env, a);
		(env->flag_ps == 1 && a >= 0) ? ft_putchar('+') : 0;
		if (env->flag_pt != -1 || a != 0)
		{
			if (((env->flag_ll == 1 || env->flag_l == 1) && env->conv == 'u') || env->conv == 'U')
				ft_putnbr_ull(a);
			else if (((env->conv == 'D' && env->flag_d == 0) || env->flag_z == 1) && a < 0 && a > -2147483648)
				ft_putnbr_ui(a);
			else
				ft_putnbr_ll(a);
		}
		else
			env->nb_char--;
	}
}

void			ft_space_char(char c, t_env *env)
{
	int			i;

	i = 0;
	if (env->flag_ms == 1)
	{
		ft_putchar(c);
		while (i < env->nb_sp - 1)
		{
			(env->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
			i++;
			env->nb_char++;
		}
	}
	else
	{
		while (i < env->nb_sp - 1)
		{
			(env->flag_zr == 1) ? ft_putchar('0') : ft_putchar(' ');
			i++;
			env->nb_char++;
		}
		ft_putchar(c);
	}
	env->nb_char++;
}
