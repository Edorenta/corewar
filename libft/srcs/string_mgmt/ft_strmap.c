/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:33:06 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:31:57 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_mgmt.h"

char	*ft_strmap(const char *str, char (*f)(char))
{
	int		i;
	char	*dst;

	if (!(str && f) || !(dst = ft_strnew(ft_strlen(str))))
		return ((void *)0);
	i = -1;
	while (str[++i])
		dst[i] = (*f)(str[i]);
	return (dst);
}
