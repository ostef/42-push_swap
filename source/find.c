/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:38:56 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/23 13:38:56 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int	find_top(t_stack *stack, t_int chunk)
{
	t_int	i;

	i = stack->count - 1;
	while (i >= 0)
	{
		if (stack->data[i].chunk == chunk)
			return (i);
		i -= 1;
	}
	return (-1);
}

t_int	find_bottom(t_stack *stack, t_int chunk)
{
	t_int	i;

	i = 0;
	while (i < stack->count)
	{
		if (stack->data[i].chunk == chunk)
			return (i);
		i += 1;
	}
	return (-1);
}

t_int	find_min(t_stack *stack)
{
	t_int	i;
	t_int	min;
	t_int	min_index;

	i = 0;
	min = S32_MAX;
	min_index = 0;
	while (i < stack->count)
	{
		if (stack->data[i].val <= min)
		{
			min = stack->data[i].val;
			min_index = i;
		}
		i += 1;
	}
	return (min_index);
}

t_int	find_max(t_stack *stack)
{
	t_int	i;
	t_int	max;
	t_int	max_index;

	i = 0;
	max = S32_MIN;
	max_index = 0;
	while (i < stack->count)
	{
		if (stack->data[i].val >= max)
		{
			max = stack->data[i].val;
			max_index = i;
		}
		i += 1;
	}
	return (max_index);
}
