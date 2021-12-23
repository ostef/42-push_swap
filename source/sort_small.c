/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:08:24 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/23 17:08:24 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_data *data)
{
	t_int	t0;
	t_int	t1;
	t_int	t2;

	t0 = data->a.data[data->a.count - 1].val;
	t1 = data->a.data[data->a.count - 2].val;
	t2 = data->a.data[data->a.count - 3].val;
	if (t2 < t1 && t1 < t0)
		sa (data);
	else if (t0 < t2 && t2 < t1)
		sa (data);
	else if (t1 < t0 && t0 < t2)
		sa (data);
	t0 = data->a.data[data->a.count - 1].val;
	t1 = data->a.data[data->a.count - 2].val;
	t2 = data->a.data[data->a.count - 3].val;
	if (t1 < t2 && t2 < t0)
		ra (data);
	else if (t2 < t0 && t0 < t1)
		rra (data);
}

static t_int	find_closest(t_data *data, t_int val)
{
	t_int	i;
	t_int	diff;
	t_int	current;
	t_int	index;

	diff = S32_MAX;
	index = 0;
	i = 0;
	while (i < data->a.count)
	{
		current = val - data->a.data[i].val;
		if (ft_abs (current) < ft_abs (diff))
		{
			diff = current;
			index = i;
		}
		i += 1;
	}
	return (index);
}

static void	move_closest(t_data *data, t_int val)
{
	t_int	i;

	i = find_closest (data, val);
	if (val - data->a.data[i].val < 0)
		move_to_top_in_a (data, i);
	else
		move_to_bottom_in_a (data, i);
}

void	sort_small(t_data *data)
{
	if (data->a.count == 2 && !is_sorted (&data->a))
		sa (data);
	else if (data->a.count == 3)
		sort_three (data);
	else if (data->a.count > 1)
	{
		while (data->a.count > 3)
			pb (data);
		sort_three (data);
		while (data->b.count > 0)
		{
			move_closest (data, data->b.data[data->b.count - 1].val);
			pa (data);
		}
		move_to_top_in_a (data, find_min (&data->a));
	}
}
