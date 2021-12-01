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
extern t_s64	g_op_count;

t_bool	init_stack(t_stack *stack, t_s64 cap);
t_int	at(t_stack *stack, t_s64 index);
t_int	bottom(t_stack *stack);
t_int	top(t_stack *stack);

t_bool	is_sorted(t_stack *stack);
void	print_stacks(void);

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
