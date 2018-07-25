/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 00:41:08 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:32:00 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_mgmt.h"
#ifndef STDDEF_H
# include <stddef.h>
#endif

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	max_len;

	i = ft_strlen(s1);
	max_len = i;
	while (s2[i - max_len] && (i - max_len) < n)
	{
		s1[i] = s2[i - max_len];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
