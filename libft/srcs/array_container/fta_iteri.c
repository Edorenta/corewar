/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_iteri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:50:34 by pde-rent          #+#    #+#             */
/*   Updated: 2017/12/13 14:23:35 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_macros.h"

void	fta_iteri(const t_array *self, void (*f)())
{
	size_t		i;
	void		*iterator;

	iterator = ARRAY_ITERATOR(self);
	i = 0;
	while (ARRAY_HASNEXT(self, iterator))
		f(i++, iterator);
}

void	fta_iteri1(const t_array *self, void (*f)(), void *ext)
{
	size_t		i;
	void		*iterator;

	iterator = ARRAY_ITERATOR(self);
	i = 0;
	while (ARRAY_HASNEXT(self, iterator))
		f(ext, i++, iterator);
}

void	fta_iteri2(const t_array *self, void (*f)(), void *ext1, void *ext2)
{
	size_t		i;
	void		*iterator;

	iterator = ARRAY_ITERATOR(self);
	i = 0;
	while (ARRAY_HASNEXT(self, iterator))
		f(ext1, ext2, i++, iterator);
}
