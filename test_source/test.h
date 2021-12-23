/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:16:10 by soumanso          #+#    #+#             */
/*   Updated: 2021/12/23 15:16:10 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "push_swap.h"

t_s64	random(void);
t_u64	urandom(void);
t_s64	random_range(t_s64 min, t_s64 max);
void	random_fill(t_data *data, t_int max);
void	benchmark(t_int chunk_count, t_int count, t_file out_file);

#endif
