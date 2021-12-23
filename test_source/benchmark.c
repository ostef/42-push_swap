/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:26:31 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/23 15:26:31 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>

typedef struct s_bench
{
	t_int	elem_count;
	t_int	min_ops;
	t_int	max_ops;
	t_int	total;
	t_int	count;
}	t_bench;

static void	benchmark_once(t_data *data, t_int index,
	t_int count, t_bench *benchs)
{
	t_int	i;

	i = 0;
	while (i < count)
	{
		ft_reset_temp_storage ();
		data->op_count = 0;
		random_fill (data, index + 1);
		if (index != 0 && is_sorted (&data->a))
			continue ;
		sort (data);
		benchs[index].total += data->op_count;
		if (data->op_count < benchs[index].min_ops)
			benchs[index].min_ops = data->op_count;
		if (data->op_count > benchs[index].max_ops)
			benchs[index].max_ops = data->op_count;
		i += 1;
	}
}

static void	print_results(t_bench *benchs, t_int chunk_count, t_int count,
	t_file out_file)
{
	t_int	i;

	i = 0;
	ft_fprintln (out_file, "======= chunk_count = %i =======", chunk_count);
	ft_fprintln (out_file, "Benchmarked %i times.", count);
	while (i < 500)
	{
		if (i >= 5 && i != 9 && (i + 1) % 100 != 0)
		{
			i += 1;
			continue ;
		}
		ft_fprint (out_file, "For %3i elements, %2i chunks: ",
			i + 1, chunk_count);
		ft_fprint (out_file, "%5i min, ", (t_int)benchs[i].min_ops);
		ft_fprint (out_file, "%5i max, ", (t_int)benchs[i].max_ops);
		dprintf (out_file, "%f avg.\n", benchs[i].total / (t_f32)count);
		i += 1;
	}
}

void	benchmark(t_int chunk_count, t_int count, t_file out_file)
{
	t_data	data;
	t_bench	benchs[500];
	t_int	i;
	t_int	j;

	data.chunk_count = chunk_count;
	i = 0;
	while (i < 500)
	{
		if (i >= 5 && i != 9 && (i + 1) % 100 != 0)
		{
			i += 1;
			continue ;
		}
		benchs[i].elem_count = i + 1;
		benchs[i].min_ops = S32_MAX;
		benchs[i].max_ops = S32_MIN;
		benchs[i].total = 0;
		benchs[i].count = count;
		benchmark_once (&data, i, count, benchs);
		i += 1;
	}
	print_results (benchs, chunk_count, count, out_file);
}
