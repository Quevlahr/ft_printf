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

// setlocale(LC_ALL, "en_US.UTF-8");


// int					main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		ft_printf("YO\n", av[1]);
// 		printf("yop%%,\n %s", av[1]);
// 	}
// 	return (0);
// }

int	main()
{
	int	i;
	int	j;

	i = ft_printf("Bonjour %0d a %d %s#0.rs coucou\n", 42, 1, "yoloswag");
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	
	j = printf("Bonjour %0d a %d %s#0.rs coucou\n", 42, 1, "yoloswag");
	printf("\n%d vs %d\n", i, j);

return (0);
}