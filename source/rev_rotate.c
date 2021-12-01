/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:09:05 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/28 19:09:05 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_rev_rotate(t_stack *stack)
{
	t_int	tmp;
	t_s64	i;

	if (stack->count < 2)
		return ;
	tmp = stack->data[0];
	i = 0;
	while (i < stack->count - 1)
	{
		stack->data[i] = stack->data[i + 1];
		i += 1;
	}
	stack->data[stack->count - 1] = tmp;
}

void	rra(void)
{
	ft_println ("rra");
	stack_rev_rotate (&g_a);
	g_op_count += 1;
}

void	rrb(void)
{
	ft_println ("rrb");
	stack_rev_rotate (&g_b);
	g_op_count += 1;
}

void	rrr(void)
{
	ft_println ("rrr");
	stack_rev_rotate (&g_a);
	stack_rev_rotate (&g_b);
	g_op_count += 1;
}
