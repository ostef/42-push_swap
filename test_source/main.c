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

t_int	main(t_int argc, t_str *args)
{
	t_data	data;
	t_int	count;

	if (argc < 2)
		return (1);
	ft_str_to_int (args[1], &count);
	ft_memset (&data, 0, sizeof (t_data));
	random_fill (&data, count);
	sort (&data);
	ft_println ("Chunk count was %i.", data.chunk_count);
	return (0);
}

/*
t_int	main(t_int argc, t_str *args)
{
	t_int	chunk;
	t_int	max_chunk;
	t_int	count;
	t_file	out_file;

	if (argc < 4)
		return (1);
	ft_str_to_int (args[1], &count);
	ft_str_to_int (args[2], &max_chunk);
	out_file = open_file_for_writing (args[3]);
	if (out_file < 0)
		return (1);
	chunk = 1;
	while (chunk <= max_chunk)
		benchmark (chunk++, count, out_file);
	close (out_file);
	return (0);
}
*/
