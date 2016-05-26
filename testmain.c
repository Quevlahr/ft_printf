/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:15:45 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/26 15:52:38 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				main(void)
{
	int	i;
	int	j;

	setlocale(LC_ALL, "en_US.UTF-8");
	i = ft_printf("[%zx, %zx]\n", 0, ULLONG_MAX);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	j = printf("[%zx, %zx]\n", 0, ULLONG_MAX);
	ft_putchar('\n');
	printf("%d vs %d\n", i, j);
	return (0);
}
