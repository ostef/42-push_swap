/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 02:43:21 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/01 02:43:21 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_s64	find_maximum(t_stack *stack)
{
	t_s64	i;
	t_s64	max_index;
	t_int	max;

	max = S32_MIN;
	max_index = S64_MIN;
	i = 0;
	while (i < stack->count)
	{
		if (at (stack, i) > max)
		{
			max = at (stack, i);
			max_index = i;
		}
		i += 1;
	}
	return (max_index);
}

static void	move_to_top(t_s64 index)
{
	if (index > g_a.count / 2)
	{
		while (index != g_a.count - 1)
		{
			ra ();
			index += 1;
		}
	}
	else
	{
		while (index != -1)
		{
			rra ();
			index -= 1;
		}
	}
}

void	sort(void)
{
	t_s64	max_index;

	while (!is_sorted (&g_a))
	{
		max_index = find_maximum (&g_a);
		move_to_top (max_index);
		pb ();
	}
	while (g_b.count > 0)
		pa ();
	ft_println ("Sorted in %i operations.", (t_int)g_op_count);
	ft_assert (is_sorted (&g_a), "Stack is not sorted.");
}
