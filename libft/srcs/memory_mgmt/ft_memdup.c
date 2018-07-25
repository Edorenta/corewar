/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:33:43 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:26:42 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_mgmt.h"
#ifndef STDLIB_H
# include <stdlib.h>
#endif

void	*ft_memdup(const void *mem1, size_t n)
{
	void	*mem2;

	if (!mem1)
		return ((void *)0);
	mem2 = (void *)malloc(n);
	if (!mem2)
		return ((void *)0);
	mem2 = ft_memcpy(mem2, mem1, n);
	return (mem2);
}
