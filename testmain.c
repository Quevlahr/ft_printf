/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:15:45 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/16 19:18:02 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				main(void)
{
	int	i;
	int	j;

	setlocale(LC_ALL, "en_US.UTF-8");

	i = ft_printf("[%30S]\n", L"ÊB");
	// i = ft_printf("[%]\n");
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	j = printf("[%30S]\n", L"ÊB");
	// j = printf("[%]\n");
	ft_putchar('\n');
	printf("%d vs %d\n", i, j);



	// printf("4567 |%-010]5d| plip\n", 12);
	// ft_printf("4567 |%-010]5d| plip\n", 12);
	return (0);
}
