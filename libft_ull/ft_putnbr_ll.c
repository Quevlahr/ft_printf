/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:26:57 by quroulon          #+#    #+#             */
/*   Updated: 2016/04/26 12:38:41 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			ft_putnbr_ll(long long nb)
{
	if (nb < -9223372036854775807)
		ft_putstr("-9223372036854775808");
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb <= 9)
			ft_putchar(nb + '0');
		else
		{
			ft_putnbr_ll(nb / 10);
			ft_putnbr_ll(nb % 10);
		}
	}
}
