/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:52:14 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/23 13:52:14 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top_in_a(t_data *data, t_int index)
{
	if (index < data->a.count / 2)
	{
		while (index >= 0)
		{
			rra (data);
			index -= 1;
		}
	}
	else
	{
		while (index < data->a.count - 1)
		{
			ra (data);
			index += 1;
		}
	}
}

void	move_to_bottom_in_a(t_data *data, t_int index)
{
	if (index < data->a.count / 2)
	{
		while (index > 0)
		{
			rra (data);
			index -= 1;
		}
	}
	else
	{
		while (index < data->a.count)
		{
			ra (data);
			index += 1;
		}
	}
}

void	move_to_top_in_b(t_data *data, t_int index)
{
	if (index < data->b.count / 2)
	{
		while (index >= 0)
		{
			rrb (data);
			index -= 1;
		}
	}
	else
	{
		while (index < data->b.count - 1)
		{
			rb (data);
			index += 1;
		}
	}
}

void	move_to_bottom_in_b(t_data *data, t_int index)
{
	if (index < data->b.count / 2)
	{
		while (index > 0)
		{
			rrb (data);
			index -= 1;
		}
	}
	else
	{
		while (index < data->b.count)
		{
			rb (data);
			index += 1;
		}
	}
}
