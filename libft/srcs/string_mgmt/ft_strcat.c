/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 00:43:11 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:31:21 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_mgmt.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	max_len;

	i = ft_strlen(s1);
	max_len = i;
	while (s2[i - max_len])
	{
		s1[i] = s2[i - max_len];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
