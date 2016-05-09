/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:15:45 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/09 12:53:38 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	
	int	i;
	int	j;
	
	i = ft_printf("[%#015.30o]\n", -128);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	j = printf("[%#015.30o]\n", -128);
	ft_putchar('\n');
	printf("%d vs %d\n", i, j);
	
	return (0);
}


// # 0094 (int)
//   ft_printf("@moulitest: %5.o", %5.0o, 0, 0);
//   1. (   22) -->@moulitest:     ,     <--
//   2. (   24) -->@moulitest:      ,      <--
