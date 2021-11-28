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

void	stack_swap(t_stack *stack)
{
	t_int	tmp;

	if (stack->count < 2)
		return ;
	tmp = stack->data[stack->count - 1];
	stack->data[stack->count - 1] = stack->data[stack->count - 2];
	stack->data[stack->count - 2] = tmp;
}

void	stack_push(t_stack *src, t_stack *dst)
{
	ft_assert (dst->count < dst->cap, "Cannot push more elements.");
	if (src->count > 0)
	{
		src->count -= 1;
		dst->data[dst->count] = src->data[src->count];
		dst->count += 1;
	}
}

void	stack_rotate(t_stack *stack)
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

void	stack_rev_rotate(t_stack *stack)
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
