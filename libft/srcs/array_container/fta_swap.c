/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:06:01 by pde-rent          #+#    #+#             */
/*   Updated: 2017/03/21 03:57:16 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_mgmt.h"
#include "array_macros.h"
#ifndef STDLIB_H
# include <stdlib.h>
#endif

/*
** Array::_swap
** -
** swaps an array segment with what follows.
** very specific function, not useful for standard cases.
** -
** "   -1415920000"
** -swap(4, 10)->
** "   -0000141592"
** -swap(0, 4)->
** "-0000141592   "
*/

void	fta_swap(t_array *self, size_t before, size_t after)
{
	char			*tmp;
	const size_t	len = after - before;
	const size_t	m = self->type_size;

	tmp = ft_safe_calloc(len, m);
	ft_memcpy(tmp, self->data + before * m, m * len);
	ft_memmove(self->data + before * m, self->data + after * m,
		(self->size - after) * m);
	ft_memcpy(self->data + (self->size - len) * m, tmp, len * m);
	free(tmp);
}
