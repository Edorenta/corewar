/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:21:32 by pde-rent          #+#    #+#             */
/*   Updated: 2017/12/12 21:05:54 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_macros.h"
#ifndef STDLIB_H
# include <stdlib.h>
#endif

/*
** Array::alloc
** -
** Allocates an array and its data.
** -
** _type_size_ should equal to the returned value of sizeof(T)
** -
** Returns the allocated array,
** or NULL if malloc failed.
*/

t_array		*fta_alloc(size_t type_size)
{
	t_array	*ret;

	if (!(ret = (t_array *)malloc(sizeof(t_array))))
		return (NULL);
	ret->type_size = type_size;
	return (fta_reserve(ret, 1) ? NULL : ret);
}
