/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:45:14 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/28 19:45:14 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_int	top(t_stack *stack)
{
	ft_assert (stack->count != 0, "Stack is empty.");
	return (stack->data[stack->count - 1]);
}

void	sort(void)
{
	while (g_a.count)
	{
		ra ();
		while (g_b.count && top (&g_b) > g_a.data[0])
			pa ();
		rra ();
		pb ();
	}
}
