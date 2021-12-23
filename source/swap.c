/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:06:32 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/23 14:06:32 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_val	temp;

	temp = stack->data[stack->count - 1];
	stack->data[stack->count - 1] = stack->data[stack->count - 2];
	stack->data[stack->count - 2] = temp;
}

void	sa(t_data *data)
{
	ft_assert (data->a.count >= 2, "sa: Stack A has less than two elements.");
	swap (&data->a);
	data->op_count += 1;
	ft_println ("sa");
}

void	sb(t_data *data)
{
	ft_assert (data->b.count >= 2, "sb: Stack B has less than two elements.");
	swap (&data->a);
	data->op_count += 1;
	ft_println ("sb");
}

void	ss(t_data *data)
{
	ft_assert (data->a.count >= 2, "ss: Stack A has less than two elements.");
	ft_assert (data->b.count >= 2, "ss: Stack B has less than two elements.");
	swap (&data->a);
	swap (&data->b);
	data->op_count += 1;
	ft_println ("ss");
}
