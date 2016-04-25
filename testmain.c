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

	i = ft_printf("[% d]\n", 42);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	j = printf("[% d]\n", 42);
	printf("\n%d vs %d\n", i, j);

return (0);
}
