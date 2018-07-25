/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:12:27 by pde-rent          #+#    #+#             */
/*   Updated: 2017/12/08 13:19:01 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_mgmt.h"
#ifndef STDLIB_H
# include <stdlib.h>
#endif

void	*ft_realloc(void *mem, size_t old_size, size_t new_size, size_t factor)
{
	void	*ret;

	ret = malloc(new_size * factor);
	if (mem == (void *)0 || ret == (void *)0)
		return (ret);
	if (new_size < old_size)
		old_size = new_size;
	ft_memcpy(ret, mem, old_size * factor);
	free(mem);
	return (ret);
}
