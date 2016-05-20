/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:15:45 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/20 20:42:09 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				main(void)
{
	int	i;
	int	j;

	setlocale(LC_ALL, "en_US.UTF-8");

	// char* l = setlocale(LC_ALL, "");
	// if (l == NULL)
	// {
	// 	printf("Locale not set\n");
	// }
	// else
	// {
	// 	printf("Locale set to %s\n", l);
	// }

	i = ft_printf("[%D]\n", -1L);
	// i = ft_printf("[%15.7S]\n",  L"42 c est cool");
	// i = ft_printf("[%jx, %jx]\n", 0, -2147483648);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	j = printf("[%D]\n", -1L);
	// j = printf("[%15.7S]\n",  L"42 c est cool");
	// j = printf("[%jx, %jx]\n", 0, -2147483648);
	ft_putchar('\n');
	printf("%d vs %d\n", i, j);





	// printf("4567 |%-010]5d| plip\n", 12);
	// ft_printf("4567 |%-010]5d| plip\n", 12);
	return (0);
}
