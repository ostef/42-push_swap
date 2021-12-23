/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:15:52 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/23 14:15:52 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_val	bottom;
	t_int	i;

	bottom = stack->data[0];
	i = 0;
	while (i < stack->count - 1)
	{
		stack->data[i] = stack->data[i + 1];
		i += 1;
	}
	stack->data[stack->count - 1] = bottom;
}

void	rra(t_data *data)
{
	ft_assert (data->a.count > 0, "rra: Stack A is empty.");
	reverse_rotate (&data->a);
	data->op_count += 1;
	ft_println ("rra");
}

void	rrb(t_data *data)
{
	ft_assert (data->b.count > 0, "rrb: Stack B is empty.");
	reverse_rotate (&data->b);
	data->op_count += 1;
	ft_println ("rrb");
}

void	rrr(t_data *data)
{
	ft_assert (data->a.count > 0, "rrr: Stack A is empty.");
	ft_assert (data->b.count > 0, "rrr: Stack B is empty.");
	reverse_rotate (&data->a);
	reverse_rotate (&data->b);
	data->op_count += 1;
	ft_println ("rrr");
}
