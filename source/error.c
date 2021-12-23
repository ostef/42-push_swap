/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:38:37 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/23 14:38:37 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_cstr	g_error_strs[] = {
	"OK.",
	"Allocation failure.",
	"Non integer value.",
	"Duplicate values."
};

void	print_error(t_result error)
{
	ft_fprintln (STDERR, "Error");
	ft_fprintln (STDERR, g_error_strs[error]);
}
