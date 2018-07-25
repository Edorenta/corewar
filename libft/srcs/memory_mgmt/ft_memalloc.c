/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:31:26 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:26:27 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_mgmt.h"
#ifndef STDLIB_H
# include <stdlib.h>
#endif

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if ((mem = malloc(size)) == (void *)0)
		return ((void *)0);
	ft_bzero(mem, size);
	return (mem);
}
