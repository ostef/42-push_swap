/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:09:12 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/28 19:09:12 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_swap(t_stack *stack)
{
	t_int	tmp;

	if (stack->count < 2)
		return ;
	tmp = stack->data[stack->count - 1];
	stack->data[stack->count - 1] = stack->data[stack->count - 2];
	stack->data[stack->count - 2] = tmp;
}

void	sa(void)
{
	ft_println ("sa");
	stack_swap (&g_a);
}

void	sb(void)
{
	ft_println ("sb");
	stack_swap (&g_b);
}

void	ss(void)
{
	ft_println ("ss");
	stack_swap (&g_a);
	stack_swap (&g_b);
}
