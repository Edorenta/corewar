/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:33:03 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:31:50 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_mgmt.h"
#ifndef STDLIB_H
# include <stdlib.h>
#endif

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len;
	char	*str;

	if (!s1 && !s2)
		return ((void *)0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return ((void *)0);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
