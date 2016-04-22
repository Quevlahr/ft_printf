/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:14:46 by quroulon          #+#    #+#             */
/*   Updated: 2016/04/04 14:14:48 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_error(t_env *env)
{
	if (env == NULL)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_FAILURE);
}

void			ft_print_env(t_env *env)
{
	ft_putstr("flag # = ");
	ft_putnbrdl(env->flag_dz);
	ft_putstr("flag 0 = ");
	ft_putnbrdl(env->flag_zr);
	ft_putstr("flag - = ");
	ft_putnbrdl(env->flag_ms);
	ft_putstr("flag + = ");
	ft_putnbrdl(env->flag_ps);
	ft_putstr("flag ' ' = ");
	ft_putnbrdl(env->flag_sp);
	ft_putstr("nb ' ' = ");
	ft_putnbrdl(env->nb_sp);
	ft_putstr("nb arg = ");
	ft_putnbrdl(env->nb_arg);
	ft_putstr("nb char = ");
	ft_putnbrdl(env->nb_char);
	ft_putstr("conversion = ");
	ft_putnbrdl(env->conv);
	ft_putchar('\n');
}

char			ft_rot_hexa(char c, int maj)
{
	if (c == '0')
		return ('0');
	if (c == '1')
		return (maj == 0) ? 'f' : 'F';
	if (c == '2')
		return (maj == 0) ? 'e' : 'E';
	if (c == '3')
		return (maj == 0) ? 'd' : 'D';
	if (c == '4')
		return (maj == 0) ? 'c' : 'C';
	if (c == '5')
		return (maj == 0) ? 'b' : 'B';
	if (c == '6')
		return (maj == 0) ? 'a' : 'A';
	if (c == '7')
		return ('9');
	if (c == '8')
		return ('8');
	if (c == '9')
		return ('7');
	if (c == 'a' || c == 'A')
		return ('6');
	if (c == 'b' || c == 'B')
		return ('5');
	if (c == 'c' || c == 'C')
		return ('4');
	if (c == 'd' || c == 'D')
		return ('3');
	if (c == 'e' || c == 'E')
		return ('2');
	// if (c == 'f' || c == 'F')
	return ('1');
	// if (c >= '1' && c <= '6' && maj == 0)
	// 	return (c + 'f');
	// if (c >= '7' && c <= '9' && maj == 0)
	// 	return (c )
}

char			*ft_negative_hexa(char *s1, int maj)
{
	int			i;
	int			j;
	char		*s2;

	i = -1;
	j = 1;
	s2 = ft_strnew(8);
	while (i++ < 7)
		s2[i] = (maj == 0) ? 'f' : 'F';
	i = 7;
	while (j < ft_strlen(s1) && i >= 0)
	{
		s2[i] = ft_rot_hexa(s1[j], maj);
		i--;
		j++;
	}
	return (s2);
}
