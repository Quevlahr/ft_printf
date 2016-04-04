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

#include "ft_printf.h"

int	main()
{
	int	i;
	int	j;

	i = 0;
	// i = ft_printf("Bonjour, %c, %d\n", 'h', 42);
	ft_printf("\n\n\n");
	j = printf("Bonjour, %bnalc, %-0 d\n", 'h', 42);
	printf("\n%d vs %d\n", i, j);

return (0);
}
