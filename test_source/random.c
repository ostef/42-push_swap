/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:15:07 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/23 15:15:07 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <unistd.h>
#include <fcntl.h>

t_s64	random(void)
{
	t_s64	result;
	t_file	fd;

	fd = open ("/dev/urandom", O_RDONLY);
	read (fd, &result, sizeof (t_s64));
	close (fd);
	return (result);
}

t_u64	urandom(void)
{
	t_u64	result;
	t_file	fd;

	fd = open ("/dev/urandom", O_RDONLY);
	read (fd, &result, sizeof (t_u64));
	close (fd);
	return (result);
}

t_s64	random_range(t_s64 min, t_s64 max)
{
	t_u64	rand;
	t_f64	t;

	rand = urandom ();
	t = (rand / (t_f64)U64_MAX) * (max - min);
	return ((t_s64)(min + t));
}
