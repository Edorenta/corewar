/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:34:02 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:26:44 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_mgmt.h"
#ifndef STDLIB_H
# include <stdlib.h>
#endif

void	*ft_memmove(void *mem2, const void *mem1, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char *)malloc(sizeof(*tmp) * n);
	if (tmp)
	{
		ft_memcpy(tmp, mem1, n);
		ft_memcpy(mem2, tmp, n);
		free(tmp);
	}
	return (mem2);
}
