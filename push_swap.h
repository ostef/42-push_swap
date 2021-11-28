/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:27:18 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/28 18:27:18 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	t_int	*data;
	t_s64	count;
	t_s64	cap;
}	t_stack;

/* Globals are supposedly bad but I'm a gangsta */

extern t_stack	g_a;
extern t_stack	g_b;

t_bool	init_stack(t_stack *stack, t_s64 cap);
void	stack_swap(t_stack *stack);
void	stack_push(t_stack *src, t_stack *dst);
void	stack_rotate(t_stack *stack);
void	stack_rev_rotate(t_stack *stack);

void	sa(void);
void	sb(void);
void	ss(void);
void	pa(void);
void	pb(void);
void	ra(void);
void	rb(void);
void	rr(void);
void	rra(void);
void	rrb(void);
void	rrr(void);
void	sort(void);

#endif
