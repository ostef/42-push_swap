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

void	rra(void)
{
	ft_println ("rra");
	stack_rev_rotate (&g_a);
}

void	rrb(void)
{
	ft_println ("rrb");
	stack_rev_rotate (&g_b);
}

void	rrr(void)
{
	ft_println ("rrr");
	stack_rev_rotate (&g_a);
	stack_rev_rotate (&g_b);
}
