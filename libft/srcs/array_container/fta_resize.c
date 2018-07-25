/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:08:29 by pde-rent          #+#    #+#             */
/*   Updated: 2017/12/12 15:01:24 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_macros.h"
#include "memory_mgmt.h"
#ifndef STDLIB_H
# include <stdlib.h>
#endif

/*
** Array::_resize
** No subtlety, just resizes the underlying array, no matter the consequences.
** However, in case of a malloc fail, the array is left untouched.
*/

int		fta_resize(t_array *self, size_t new_size)
{
	void	*tmp;

	tmp = malloc(new_size * self->type_size);
	if (tmp == NULL)
		return (1);
	if (self->size > new_size)
		self->size = new_size;
	ft_memcpy(tmp, self->data, self->size * self->type_size);
	free(self->data);
	self->data = tmp;
	self->max = new_size;
	return (0);
}
