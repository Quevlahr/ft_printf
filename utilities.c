/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:14:46 by quroulon          #+#    #+#             */
/*   Updated: 2016/04/04 14:14:48 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_error(t_env *env)
{
	if (env == NULL)
	{
		ft_putendl("Error");
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_putendl("Error");
		exit(EXIT_FAILURE);
	}
}
