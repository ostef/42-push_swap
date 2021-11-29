/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:09:08 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/28 19:09:08 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_rotate(t_stack *stack)
{
	t_int	tmp;
	t_s64	i;

	if (stack->count < 2)
		return ;
	tmp = stack->data[stack->count - 1];
	i = stack->count - 2;
	while (i >= 0)
	{
		stack->data[i + 1] = stack->data[i];
		i -= 1;
	}
	stack->data[0] = tmp;
}

void	ra(void)
{
	ft_println ("ra");
	stack_rotate (&g_a);
}

void	rb(void)
{
	ft_println ("rb");
	stack_rotate (&g_b);
}

void	rr(void)
{
	ft_println ("rr");
	stack_rotate (&g_a);
	stack_rotate (&g_b);
}
