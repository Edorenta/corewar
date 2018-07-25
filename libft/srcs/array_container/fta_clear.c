/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:46:25 by pde-rent          #+#    #+#             */
/*   Updated: 2017/12/12 19:01:26 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_macros.h"
#ifndef STDLIB_H
# include <stdlib.h>
#endif

/*
** Array::clear
** -
** Frees the underlying data, but leaves the array usable :
** one might still call the append function, the array was only
** emptied.
*/

void	fta_clear(t_array *self)
{
	if (self->max > 0)
	{
		free(self->data);
		self->size = 0;
		self->max = 0;
	}
}
