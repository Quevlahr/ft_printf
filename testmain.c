/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:15:45 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/10 20:39:06 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	
	int	i;
	int	j;
	
	i = ft_printf("[%zd]\n", 4294967295);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	j = printf("[%zd]\n", 4294967295);
	ft_putchar('\n');
	printf("%d vs %d\n", i, j);
	
	printf("4567 |%-010]5d| plip\n", 12);
	ft_printf("4567 |%-010]5d| plip\n", 12);
	return (0);
}
