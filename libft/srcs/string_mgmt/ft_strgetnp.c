/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgetnp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:54:23 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:06:50 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char_class.h"
#include "non_printables.h"
#include "string_mgmt.h"
#ifndef STDLIB_H
# include <stdlib.h>
#endif

static inline char	*get_non_printable(char *str, int n, int i, int j)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (n + 5));
	while (str[++j])
	{
		if (ft_isprint(str[j]))
			tmp[++i] = str[j];
		else if (NON_PRINT[str[j] * 3 + 2])
		{
			tmp[++i] = '[';
			tmp[++i] = NON_PRINT[str[j] * 3];
			tmp[++i] = NON_PRINT[str[j] * 3 + 1];
			tmp[++i] = NON_PRINT[str[j] * 3 + 2];
			tmp[++i] = ']';
		}
		else
		{
			tmp[++i] = '[';
			tmp[++i] = NON_PRINT[str[j] * 3];
			tmp[++i] = NON_PRINT[str[j] * 3 + 1];
			tmp[++i] = ']';
		}
	}
	ft_strcat(tmp, "[NUL]\0");
	return (tmp);
}

char				*ft_strgetnp(char *str)
{
	int	i;
	int j;

	i = -1;
	j = 0;
	while (str[++i])
		if (!ft_isprint(str[i]))
			j += 2;
	return (get_non_printable(str, j + i, -1, -1));
}
