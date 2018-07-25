/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 00:41:17 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:32:06 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_mgmt.h"
#ifndef STDLIB_H
# include <stdlib.h>
#endif

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	int i;
	int j;
	int back_up_i;

	i = 0;
	j = 0;
	if (ft_strlen(find) == 0)
		return ((char *)str);
	while ((str[i] && i != (int)n) && find[j])
	{
		back_up_i = i;
		while ((str[i] == find[j]) && i != (int)n)
		{
			if ((size_t)j == (ft_strlen(find) - 1))
				return ((char *)&str[i - j]);
			j++;
			i++;
		}
		i = back_up_i;
		i++;
		j = 0;
	}
	return (0);
}
