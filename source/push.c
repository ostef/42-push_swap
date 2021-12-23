/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:03:58 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/23 14:03:58 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	ft_assert (data->b.count > 0, "pa: Stack B is empty.");
	data->b.count -= 1;
	data->a.data[data->a.count] = data->b.data[data->b.count];
	data->a.count += 1;
	data->op_count += 1;
	ft_println ("pa");
}

void	pb(t_data *data)
{
	ft_assert (data->a.count > 0, "pb: Stack A is empty.");
	data->a.count -= 1;
	data->b.data[data->b.count] = data->a.data[data->a.count];
	data->b.count += 1;
	data->op_count += 1;
	ft_println ("pb");
}
