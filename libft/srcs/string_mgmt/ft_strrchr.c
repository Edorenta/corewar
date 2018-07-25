/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 00:41:20 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:10:20 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_mgmt.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;

	len = ft_strlen((char *)str);
	while (0 != len && str[len] != (char)c)
		len--;
	if (str[len] == (char)c)
		return ((char *)&str[len]);
	return ((void *)0);
}
