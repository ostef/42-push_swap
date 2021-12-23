/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:10:00 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/23 12:10:00 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int	main(t_int argc, t_str *args)
{
	t_data		data;
	t_result	res;

	ft_memset (&data, 0, sizeof (t_data));
	if (argc < 2)
		return (0);
	res = parse_args (&data, args + 1, argc - 1);
	if (res != OK)
	{
		print_error (res);
		return (1);
	}
	sort (&data);
	return (0);
}
