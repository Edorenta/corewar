/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:33:09 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:31:58 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_mgmt.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dst;

	if (!(str && f && *f) || !(dst = ft_strnew(ft_strlen(str))))
		return ((void *)0);
	i = -1;
	while (str[++i])
		dst[i] = (*f)(i, str[i]);
	return (dst);
}
