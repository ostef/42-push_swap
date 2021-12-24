/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:44:55 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/24 10:44:55 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	skip_spaces(t_cstr *str)
{
	while (ft_is_space (**str))
		*str += 1;
}

static t_bool	int_is_outside_bounds(t_u64 uval, t_int sign, t_int next_digit)
{
	if (uval > S32_MAX / 10)
		return (TRUE);
	if (sign == 1 && uval * 10 + next_digit > S32_MAX)
		return (TRUE);
	if (sign == -1 && uval * 10 + next_digit > -S32_MIN)
		return (TRUE);
	return (FALSE);
}

t_result	parse_int(t_cstr *str, t_int *out)
{
	t_u64		val;
	t_int		sign;
	t_result	res;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		sign = (**str == '+') * 2 - 1;
		*str += 1;
	}
	res = OK;
	val = 0;
	while (**str && !ft_is_space (**str))
	{
		if (int_is_outside_bounds (val, sign, (**str) - '0'))
			res = INT_VALUE_OUTSIDE_BOUNDS;
		if (!ft_is_digit (**str))
			res = NOT_AN_INTEGER;
		val *= 10;
		val += (**str) - '0';
		*str += 1;
	}
	*out = sign * val;
	return (res);
}
