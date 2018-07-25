/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_popback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:08:29 by pde-rent          #+#    #+#             */
/*   Updated: 2017/03/21 05:32:50 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_macros.h"
#include "private_macros.h"

/*
** Array::pop_back
** -
** Removes at most _len_ elements at the end.
** -
** _len_ is the number of elements to be removed.
*/

void	fta_popback(t_array *self, size_t len)
{
	self->size -= _MIN2(len, self->size);
}

/*
** Array::pop_back w/ function
** -
** Same as pop_back, but provides a way to avoid leaks by freeing
** contents pointed by the poped elements.
** -
** _len_ is the number of elements to be removed.
** _del_ is a function that knows how to properly free a single element's
** contents from its address.
*/

void	fta_popbackf(t_array *self, size_t len, void (*del)(void *))
{
	while (self->size > 0 && len > 0)
	{
		self->size--;
		del(ARRAY_END(self));
		len--;
	}
}
