/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:09:02 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/28 19:09:02 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_push(t_stack *src, t_stack *dst)
{
	if (src->count > 0)
	{
		ft_assert (dst->count < dst->cap, "Cannot push more elements.");
		src->count -= 1;
		dst->data[dst->count] = src->data[src->count];
		dst->count += 1;
	}
}

void	pa(void)
{
	ft_println ("pa");
	stack_push (&g_b, &g_a);
}

void	pb(void)
{
	ft_println ("pb");
	stack_push (&g_a, &g_b);
}
