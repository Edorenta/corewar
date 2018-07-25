/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 00:41:02 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:43:08 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_mgmt.h"
#ifndef STDDEF_H
# include <stddef.h>
#endif

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_dst;
	size_t len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (len_src + size);
	else
		ft_strncat(dst, src, size - len_dst - 1);
	return (len_dst + len_src);
}
