/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:32:19 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 15:02:24 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_mgmt.h"

char	*ft_strtok(char *str, const char *sep)
{
	char	*strend;
	int		c;

	c = 0;
	if (!str)
		return ((void *)0);
	while (ft_strchr(sep, c))
		if ((c = *str++) == '\0')
			return (0);
	--str;
	strend = str + ft_strcspn(str, sep);
	if (*strend != 0)
		*strend++ = '\0';
	return (str);
}
