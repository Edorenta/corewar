/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:33:20 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:32:14 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_mgmt.h"
#ifndef STDLIB_H
# include <stdlib.h>
#endif

char		**ft_strsplit(const char *str, char c)
{
	size_t	i;
	size_t	j;
	int		first;
	int		last;
	char	**tab;

	tab = (void *)0;
	i = 0;
	j = 0;
	if (str && (tab = (char **)malloc(sizeof(*tab) * (ft_strlen(str) + 2))))
	{
		while (str[i])
		{
			while (str[i] && str[i] == c)
				i++;
			first = i;
			while (str[i] && str[i] != c)
				i++;
			last = i;
			if (last > first)
				tab[j++] = ft_strsub(str, first, (last - first));
		}
		tab[j] = (void *)0;
	}
	return (tab);
}
