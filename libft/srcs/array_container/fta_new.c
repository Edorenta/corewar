/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:41:24 by pde-rent          #+#    #+#             */
/*   Updated: 2017/12/12 21:05:37 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_macros.h"

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

t_array		fta_new(size_t type_size)
{
	t_array		ret;

	ret = (t_array){NULL, 0, 0, type_size};
	fta_reserve(&ret, 1);
	return (ret);
}
