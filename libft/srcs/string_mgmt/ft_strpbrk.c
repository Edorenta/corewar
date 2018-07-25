/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 00:40:45 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:31:22 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_mgmt.h"

char	*ft_strpbrk(const char *str, const char *lst)
{
	int		i;
	int		max;
	char	match;

	max = ft_strlen(lst);
	match = 0;
	while (*str && !match && (i = -1))
	{
		while (++i < max)
			if (*str == lst[i] && *str != '\0' && (match = 1))
				break ;
		str++;
	}
	return (match ? (char *)(--str) : (void *)0);
}
