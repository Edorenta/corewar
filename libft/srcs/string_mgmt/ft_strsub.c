/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:33:23 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 15:03:00 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDLIB_H
# include <stdlib.h>
#endif

char	*ft_strsub(const char *str, unsigned int start, size_t n)
{
	int		i;
	char	*tmp;

	if (!str || !(tmp = (char *)malloc(sizeof(*tmp) * (n + 1))))
		return ((void *)0);
	i = 0;
	while (n - i)
	{
		tmp[i] = str[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
