/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:41:55 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/23 14:41:55 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_result	set_values(t_data *data, t_int *ints, t_int count)
{
	t_int	i;
	t_int	j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < i)
		{
			if (ints[i] == ints[j])
				return (DUPLICATE_VALUES);
			j += 1;
		}
		data->a.data[count - i - 1].val = ints[i];
		i += 1;
	}
	return (OK);
}

static void	sort_ints(t_int *ints, t_int count)
{
	t_int	i;
	t_int	temp;

	i = 0;
	while (i < count - 1)
	{
		if (ints[i] < ints[i + 1])
		{
			temp = ints[i];
			ints[i] = ints[i + 1];
			ints[i + 1] = temp;
			i = 0;
		}
		else
			i += 1;
	}
}

static void	set_sort_indices(t_data *data, t_int *ints, t_int count)
{
	t_int	i;
	t_int	j;

	sort_ints (ints, count);
	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (data->a.data[i].val == ints[j])
			{
				data->a.data[i].sort_index = j;
				data->a.data[i].chunk = j * data->chunk_count / count;
				break ;
			}
			j += 1;
		}
		i += 1;
	}
}

t_result	fill_stack(t_data *data, t_int *ints, t_int count)
{
	t_result	res;

	data->chunk_count = (t_int)(0.012f * count + 6.2);
	data->a.data = (t_val *)ft_alloc (sizeof (t_val) * count, ALLOC_TEMP);
	data->a.count = count;
	data->b.data = (t_val *)ft_alloc (sizeof (t_val) * count, ALLOC_TEMP);
	data->b.count = 0;
	res = set_values (data, ints, count);
	if (res != OK)
		return (res);
	set_sort_indices (data, ints, count);
	return (OK);
}
