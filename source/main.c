/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:52:08 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/28 18:52:08 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	g_a;
t_stack	g_b;

static t_bool	parse_args(t_str args[], t_int count)
{
	t_s64	i;
	t_s64	j;

	while (g_a.count < count)
	{
		ft_str_to_int (args[g_a.count], g_a.data + g_a.count);
		g_a.count += 1;
	}
	i = 0;
	while (i < g_a.count)
	{
		j = 0;
		while (j < g_a.count)
		{
			if (i != j && g_a.data[i] == g_a.data[j])
				return (FALSE);
			j += 1;
		}
		i += 1;
	}
	return (TRUE);
}

t_int	main(t_int argc, t_str args[])
{
	if (argc < 2)
		return (0);
	if (!init_stack (&g_a, argc - 1))
	{
		ft_fprintln (STDERR, "Error");
		return (1);
	}
	if (!init_stack (&g_b, argc - 1))
	{
		ft_fprintln (STDERR, "Error");
		return (1);
	}
	if (!parse_args (args + 1, argc - 1))
	{
		ft_fprintln (STDERR, "Error");
		return (1);
	}
	sort ();
}
