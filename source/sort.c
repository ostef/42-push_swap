/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:19:03 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/23 12:19:03 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_int	push_next_elem_to_b(t_data *data, t_int chunk)
{
	t_int	top;
	t_int	bottom;

	top = find_top (&data->a, chunk);
	if (top == -1)
		return (chunk + 1);
	bottom = find_bottom (&data->a, chunk);
	if (data->a.count - top - 1 < bottom)
		move_to_top_in_a (data, top);
	else
		move_to_top_in_a (data, bottom);
	move_to_top_in_b (data, find_min (&data->b));
	pb (data);
	return (chunk);
}

t_bool	is_sorted(t_stack *stack)
{
	t_int	i;

	i = 0;
	while (i < stack->count - 1)
	{
		if (stack->data[i].sort_index != stack->data[i + 1].sort_index - 1)
			return (FALSE);
		i += 1;
	}
	return (TRUE);
}

void	sort(t_data *data)
{
	t_int	chunk;

	if (is_sorted (&data->a))
		return ;
	if (data->a.count <= 30)
		sort_small (data);
	else
	{
		chunk = 0;
		while (data->a.count > 0)
			chunk = push_next_elem_to_b (data, chunk);
		while (data->b.count > 0)
		{
			move_to_top_in_b (data, find_max (&data->b));
			pa (data);
		}
	}
	ft_assert (is_sorted (&data->a), "Stack is not sorted.");
	ft_fprintln (STDERR, "Sorted in %i operations.", data->op_count);
}
