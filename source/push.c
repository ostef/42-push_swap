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
