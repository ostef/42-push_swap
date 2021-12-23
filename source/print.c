/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:41:24 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/23 15:41:24 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_data *data)
{
	t_int	i;

	i = ft_max (data->a.count, data->b.count) - 1;
	while (i >= 0)
	{
		if (i < data->a.count)
			ft_print ("|%3i|   ", data->a.data[i].val);
		else
			ft_print ("        ");
		if (i < data->b.count)
			ft_print ("|%3i|\n", data->b.data[i].val);
		else
			ft_print ("\n");
		i -= 1;
	}
	ft_println ("=====   =====");
	ft_println ("| a |   | b |");
}
