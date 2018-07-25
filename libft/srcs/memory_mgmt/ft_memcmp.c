/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:33:57 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:26:34 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_mgmt.h"

int		ft_memcmp(const void *mem1, const void *mem2, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		if (((unsigned char *)mem1)[i] != ((unsigned char *)mem2)[i])
			return (((unsigned char *)mem1)[i] - ((unsigned char *)mem2)[i]);
	return (0);
}
