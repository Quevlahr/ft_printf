/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:15:45 by quroulon          #+#    #+#             */
/*   Updated: 2016/03/31 15:15:48 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// int					main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		ft_printf("YO\n", av[1]);
// 		printf("yop%%,\n %s", av[1]);
// 	}
// 	return (0);
// }

int				main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	
	int	i;
	int	j;

	i = ft_printf("[%x, %x]", 15, -12);
	// i = ft_printf("Bon%5%jour %0d %s#0.rs\n", 42, "yoloswag");
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	
	j = printf("[%x, %x]", 15, -12);
	// j = printf("Bon%5%jour %0d %s#0.rs\n", 42, "yoloswag");
	printf("\n%d vs %d\n", i, j);

return (0);
}


// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
// 0 F E D C B A 9 8 7 6  5  4  3  2  1


// 0 1 2 3 4 5 6 7 8 9 A  B  C  D  E  F
// 0 F