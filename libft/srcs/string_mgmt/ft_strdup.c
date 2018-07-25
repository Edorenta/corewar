/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 00:40:59 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:31:37 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_mgmt.h"
#ifndef STDLIB_H
# include <stdlib.h>
#endif

char	*ft_strdup(const char *src)
{
	char	*dst;

	dst = (char *)malloc(sizeof(*dst) * (ft_strlen(src) + 1));
	return ((!dst) ? NULL : ft_strcpy(dst, src));
}
