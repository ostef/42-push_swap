/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:26:36 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/23 15:26:36 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

void	random_fill(t_data *data, t_int max)
{
	t_int	i;
	t_int	j;
	t_int	*ints;

	ints = ft_alloc (max * sizeof (t_int), ALLOC_TEMP);
	i = 0;
	while (i < max)
	{
		ints[i] = (t_int)random_range (0, max);
		j = 0;
		while (j < i)
		{
			if (ints[j] == ints[i])
			{
				ints[i] = (t_int)random_range (0, max);
				j = 0;
			}
			else
				j += 1;
		}
		i += 1;
	}
	fill_stack (data, ints, max);
}

static t_file	open_file_for_writing(t_cstr filename)
{
	t_file	result;

	result = open (filename, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	if (result < 0)
		ft_fprintln (STDERR,
			"Error\nCould not open file '%\\s': %s",
			filename, strerror (errno));
	return (result);
}

static t_int	test_random(t_str *args, t_int argc)
{
	t_data	data;
	t_int	count;

	if (argc < 1)
	{
		ft_fprintln (STDERR, "Usage: test --random elem_count");
		return (1);
	}
	ft_str_to_int (args[0], &count);
	ft_memset (&data, 0, sizeof (t_data));
	random_fill (&data, count);
	sort (&data);
	return (0);
}

static t_int	test_benchmark(t_str *args, t_int argc)
{
	t_int	count;
	t_file	out_file;

	if (argc < 2)
	{
		ft_fprintln (STDERR, "Usage: test --benchmark count out_filename");
		return (1);
	}
	ft_str_to_int (args[0], &count);
	out_file = open_file_for_writing (args[1]);
	if (out_file < 0)
		return (1);
	benchmark (count, out_file);
	close (out_file);
	return (0);
}

t_int	main(t_int argc, t_str *args)
{
	if (argc < 2)
	{
		ft_fprintln (STDERR, "Usage: test action args");
		ft_fprintln (STDERR, "Example:");
		ft_fprintln (STDERR, "       test --random elem_count");
		ft_fprintln (STDERR, "       test --benchmark count out_filename");
		return (1);
	}
	if (ft_strequ (args[1], "--random"))
		return (test_random (args + 2, argc - 2));
	else if (ft_strequ (args[1], "--benchmark"))
		return (test_benchmark (args + 2, argc - 2));
	return (0);
}
