/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:09:33 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/23 12:09:33 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_val
{
	t_int	val;
	t_int	sort_index;
	t_int	chunk;
}	t_val;

typedef struct s_stack
{
	t_val	*data;
	t_int	count;
}	t_stack;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
	t_int	chunk_count;
	t_int	op_count;
}	t_data;

typedef enum e_result
{
	OK = 0,
	ALLOCATION_FAILURE = 1,
	NOT_AN_INTEGER = 2,
	DUPLICATE_VALUES = 3
}	t_result;

t_result	parse_args(t_data *data, t_str *args, t_int argc);
t_result	fill_stack(t_data *data, t_int *ints, t_int count);
void		print_error(t_result error);

/* Primitive operations */

void		pa(t_data *data);
void		pb(t_data *data);
void		sa(t_data *data);
void		sb(t_data *data);
void		ss(t_data *data);
void		ra(t_data *data);
void		rb(t_data *data);
void		rr(t_data *data);
void		rra(t_data *data);
void		rrb(t_data *data);
void		rrr(t_data *data);

void		move_to_top_in_a(t_data *data, t_int index);
void		move_to_bottom_in_a(t_data *data, t_int index);
void		move_to_top_in_b(t_data *data, t_int index);
void		move_to_bottom_in_b(t_data *data, t_int index);
t_int		find_top(t_stack *stack, t_int chunk);
t_int		find_bottom(t_stack *stack, t_int chunk);
t_int		find_min(t_stack *stack);
t_int		find_max(t_stack *stack);
t_bool		is_sorted(t_stack *stack);
void		sort_small(t_data *data);
void		sort(t_data *data);

/* Debug */

void		print_stacks(t_data *data);

#endif
