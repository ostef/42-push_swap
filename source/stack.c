/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:30:58 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/28 18:30:58 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	init_stack(t_stack *stack, t_s64 cap)
{
	stack->data = (t_int *)ft_alloc (sizeof (t_int) * cap, ALLOC_TEMP);
	if (!stack->data)
	{
		stack->count = 0;
		stack->cap = 0;
		return (FALSE);
	}
	stack->count = 0;
	stack->cap = cap;
	return (TRUE);
}

t_int	at(t_stack *stack, t_s64 index)
{
	ft_assert (stack->count > 0, "Stack is empty.");
	ft_assert (index >= 0 && index < stack->count,
		"Invalid index (got %i, max is %i).", index, stack->count - 1);
	return (stack->data[index]);
}

t_int	bottom(t_stack *stack)
{
	return at (stack, 0);
}

t_int	top(t_stack *stack)
{
	return at (stack, stack->count - 1);
}
