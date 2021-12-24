/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:25:06 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/23 14:25:06 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_ints
{
	t_int	*data;
	t_int	count;
	t_int	cap;
}	t_ints;

static t_result	push_value(t_ints *ints, t_int val)
{
	if (ints->count >= ints->cap)
	{
		ints->data = (t_int *)ft_realloc (ints->data,
				ints->cap * sizeof (t_int),
				(ints->cap * 2 + 8) * sizeof (t_int), ALLOC_TEMP);
		if (!ints->data)
			return (ALLOCATION_FAILURE);
		ints->cap += ints->cap + 8;
	}
	ints->data[ints->count] = val;
	ints->count += 1;
	return (OK);
}

static t_result	parse_str(t_ints *ints, t_cstr str)
{
	t_int		current;
	t_result	res;

	while (*str)
	{
		skip_spaces (&str);
		if (*str == 0)
			break ;
		res = parse_int (&str, &current);
		if (res != OK)
			return (res);
		res = push_value (ints, current);
		if (res != OK)
			return (res);
	}
	return (OK);
}

t_result	parse_args(t_data *data, t_str *args, t_int argc)
{
	t_int		i;
	t_result	res;
	t_ints		ints;

	ft_memset (&ints, 0, sizeof (t_ints));
	ints.cap = 100;
	ints.data = (t_int *)ft_alloc (sizeof (t_int) * ints.cap, ALLOC_TEMP);
	if (!ints.data)
		return (ALLOCATION_FAILURE);
	i = 0;
	while (i < argc)
	{
		res = parse_str (&ints, args[i]);
		if (res != OK)
			return (res);
		i += 1;
	}
	res = fill_stack (data, ints.data, ints.count);
	if (res != OK)
		return (res);
	return (OK);
}
