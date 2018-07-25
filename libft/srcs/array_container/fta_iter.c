/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:50:34 by pde-rent          #+#    #+#             */
/*   Updated: 2017/12/13 14:18:49 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_macros.h"

void	fta_iter(const t_array *self, void (*f)())
{
	void		*iterator;

	iterator = ARRAY_ITERATOR(self);
	while (ARRAY_HASNEXT(self, iterator))
		f(iterator);
}

void	fta_iter1(const t_array *self, void (*f)(), void *ext)
{
	void		*iterator;

	iterator = ARRAY_ITERATOR(self);
	while (ARRAY_HASNEXT(self, iterator))
		f(ext, iterator);
}

void	fta_iter2(const t_array *self, void (*f)(), void *ext1, void *ext2)
{
	void		*iterator;

	iterator = ARRAY_ITERATOR(self);
	while (ARRAY_HASNEXT(self, iterator))
		f(ext1, ext2, iterator);
}
