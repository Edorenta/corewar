/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:33:52 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:26:29 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_mgmt.h"

void	*ft_memccpy(void *mem2, const void *mem1, int c, size_t len)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	*dst;

	i = 0;
	src = (unsigned char *)mem1;
	dst = (unsigned char *)mem2;
	while (i < len)
	{
		dst[i] = src[i];
		if (src[i] == (unsigned char)c)
			return (mem2 + i + 1);
		i++;
	}
	return ((void *)0);
}
