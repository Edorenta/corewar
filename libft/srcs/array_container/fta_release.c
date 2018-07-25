/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 12:09:07 by pde-rent          #+#    #+#             */
/*   Updated: 2017/12/13 09:17:19 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_macros.h"
#ifndef STDLIB_H
# include <stdlib.h>
#endif

/*
** Array::release
** -
** If one initialised the array with fta_alloc, they are advised
** to use fta_release to free it.
** Both the underlying data and the array will be freed.
** -
** _ptr_ is the address of a pointer to an array,
** and will be set to NULL to prevent further uses attempts.
*/

void	fta_release(t_array **ptr)
{
	fta_clear(*ptr);
	free(*ptr);
	*ptr = NULL;
}
