/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:15:45 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/05 18:10:49 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	
	int	i;
	int	j;

	// i = ft_printf("[% 10.5d]\n", 4242);
	i = ft_printf("[%U]\n", 4294967296);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	// j = printf("[% 10.5d]\n", 4242);
	j = printf("[%U]\n", 4294967296);
	ft_putchar('\n');
	printf("%d vs %d\n", i, j);

return (0);
}


// # 0094 (int)
//   ft_printf("@moulitest: %5.o", %5.0o, 0, 0);
//   1. (   22) -->@moulitest:     ,     <--
//   2. (   24) -->@moulitest:      ,      <--
