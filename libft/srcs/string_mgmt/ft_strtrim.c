/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:33:26 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 17:11:43 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char_class.h"
#include "string_mgmt.h"
#ifndef STDDEF_H
# include <stddef.h>
#endif

static int		is_space(char c)
{
	return ((c == ' ' || c == '\n' || c == '\t') ? 1 : 0);
}

char			*ft_strtrim(const char *str)
{
	size_t	min;
	size_t	max;
	size_t	len;

	if (!str)
		return ((void *)0);
	min = 0;
	while (str[min] != '\0' && is_space((char)str[min]))
		min++;
	max = ft_strlen(str);
	while (min < max && is_space((char)str[max - 1]))
		max--;
	if (min == max)
		return (ft_strnew(1));
	len = max - min;
	return (ft_strsub(str, min, len));
}
