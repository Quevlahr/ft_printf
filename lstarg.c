/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstarg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 19:58:16 by quroulon          #+#    #+#             */
/*   Updated: 2016/04/04 19:58:37 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void			ft_initlstend(t_arg **arg)
// {
// 	t_arg		*tmp_arg;

// 	tmp_arg = *arg;
// 	while ((*arg)->next)
// 	{
// 	ft_putendl("fin?");

// 		*arg = (*arg)->next;
// 	}
// 	tmp_arg = tmp_arg->start;
// 	while (tmp_arg->next)
// 	{
// 		tmp_arg->end = (*arg);
// 		tmp_arg = tmp_arg->next;		
// 	}
// }

// t_arg			*ft_argnew(t_help help)
// {
// 	t_arg		*new_arg;

// 	if (!(new_arg = (t_arg*)malloc(sizeof(t_arg))))
// 		ft_error(NULL);
// 	new_arg->next = NULL;
// 	new_arg->prev = NULL;
// 	new_arg->flag_dz = help.flag_dz;
// 	new_arg->flag_zr= help.flag_zr;
// 	new_arg->flag_ms= help.flag_ms;
// 	new_arg->flag_ps = help.flag_ps;
// 	new_arg->flag_sp = help.flag_sp;
// 	new_arg->conv = help.conv;
//  	return (new_arg);
// }

// void			ft_argpush(t_arg **arg, t_help help)
// {
// 	t_arg		*prev_arg;

// 	if ((*arg))
// 	{
// 		while ((*arg)->next)
// 			(*arg) = (*arg)->next;
// 		prev_arg = (*arg);
// 		(*arg)->next = ft_argnew(help);
// 		(*arg) = (*arg)->next;
// 		(*arg)->prev = prev_arg;
// 		(*arg)->start = prev_arg->start;
// 		(*arg)->end = (*arg);
// 	}
// 	else
// 	{
// 		(*arg) = ft_argnew(help);
// 		(*arg)->start = (*arg);
// 		(*arg)->end = (*arg);
// 		(*arg) = (*arg)->start;
// 	}
// }
