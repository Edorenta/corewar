/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 00:41:25 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:32:16 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_mgmt.h"
#ifndef STDDEF_H
# include <stddef.h>
#endif

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;
	int back_up_i;

	i = 0;
	j = 0;
	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	while (str[i] && to_find[j])
	{
		back_up_i = i;
		while (str[i] == to_find[j])
		{
			if ((size_t)j == (ft_strlen(to_find) - 1))
				return ((char *)&str[i - j]);
			j++;
			i++;
		}
		i = back_up_i;
		i = i + 1;
		j = 0;
	}
	return (0);
}
