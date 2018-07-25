/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 22:10:21 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/25 22:11:01 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*copy;
	int		i;
	int		len;

	i = 0;
	if (n > ft_strlen(s1))
		len = ft_strlen(s1);
	else
		len = n;
	if ((copy = (char*)malloc(sizeof(char) * (len + 1))))
	{
		while (i < len)
		{
			copy[i] = s1[i];
			i++;
		}
		copy[i] = '\0';
		return (copy);
	}
	else
		return (NULL);
}

int		ft_skip_whitespace(char *str, int i)
{
	while (ft_isspace(str[i]))
		i++;
	return (i);
}
