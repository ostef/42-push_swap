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
#include <stdio.h>

t_stack	g_a;
t_stack	g_b;

static t_bool	parse_args(t_str *args, t_int count)
{
	t_s64	i;
	t_s64	j;

	while (g_a.count < count)
	{
		ft_str_to_int (args[g_a.count], g_a.data + count - g_a.count - 1);
		g_a.count += 1;
	}
	i = 0;
	while (i < g_a.count)
	{
		j = 0;
		while (j < g_a.count)
		{
			if (i != j && g_a.data[i] == g_a.data[j])
			{
				ft_println ("%i twice (%i and %i).", g_a.data[i], i, j);
				return (FALSE);
			}
			j += 1;
		}
		i += 1;
	}
	return (TRUE);
}

static t_bool	is_sorted(void)
{
	t_s64	i;

	i = 0;
	while (i < g_a.count - 1)
	{
		if (g_a.data[i] > g_a.data[i + 1])
			return (FALSE);
		i += 1;
	}
	return (TRUE);
}

static void	print_stacks(void)
{
	t_s64	i;

	i = ft_max (g_a.count, g_b.count) - 1;
	while (i >= 0)
	{
		if (i < g_a.count)
			ft_print ("|%3i|   ", g_a.data[i]);
		else
			ft_print ("        ");
		if (i < g_b.count)
			ft_print ("|%3i|\n", g_b.data[i]);
		else
			ft_print ("\n");
		i -= 1;
	}
	ft_println ("=====   =====");
	ft_println ("| a |   | b |");
}

t_int	main(t_int argc, t_str *args)
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
	print_stacks ();
	char	op[100];
	while (!is_sorted () || g_b.count > 0)
	{
		scanf ("%s", op);
		if (ft_strequ (op, "sa"))
			sa ();
		else if (ft_strequ (op, "sb"))
			sb ();
		else if (ft_strequ (op, "ss"))
			ss ();
		else if (ft_strequ (op, "pa"))
			pa ();
		else if (ft_strequ (op, "pb"))
			pb ();
		else if (ft_strequ (op, "ra"))
			ra ();
		else if (ft_strequ (op, "rb"))
			rb ();
		else if (ft_strequ (op, "rr"))
			rr ();
		else if (ft_strequ (op, "rra"))
			rra ();
		else if (ft_strequ (op, "rrb"))
			rrb ();
		else if (ft_strequ (op, "rrr"))
			rrr ();
		else if (ft_strequ (op, "reset"))
		{
			g_a.count = 0;
			g_b.count = 0;
			parse_args (args + 1, argc - 1);
		}
		else
		{
			ft_println ("Invalid op (%s).", op);
			continue ;
		}
		print_stacks ();
	}
}
