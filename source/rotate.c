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
