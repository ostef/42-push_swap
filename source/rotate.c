/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:10:18 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/23 14:10:18 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_val	top;
	t_int	i;

	top = stack->data[stack->count - 1];
	i = stack->count - 1;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i -= 1;
	}
	stack->data[0] = top;
}

void	ra(t_data *data)
{
	ft_assert (data->a.count > 0, "ra: Stack A is empty.");
	rotate (&data->a);
	data->op_count += 1;
	ft_println ("ra");
}

void	rb(t_data *data)
{
	ft_assert (data->b.count > 0, "rb: Stack B is empty.");
	rotate (&data->b);
	data->op_count += 1;
	ft_println ("rb");
}

void	rr(t_data *data)
{
	ft_assert (data->a.count > 0, "rr: Stack A is empty.");
	ft_assert (data->b.count > 0, "rr: Stack B is empty.");
	rotate (&data->a);
	rotate (&data->b);
	data->op_count += 1;
	ft_println ("rr");
}
