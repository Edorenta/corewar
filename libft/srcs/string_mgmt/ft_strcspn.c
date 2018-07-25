/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:31:27 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:57:20 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_mgmt.h"

size_t	ft_strcspn(const char *str, const char *rej)
{
	size_t cnt;

	cnt = 0;
	while (ft_strchr(rej, *str) == 0)
	{
		++cnt;
		++str;
	}
	return (cnt);
}
