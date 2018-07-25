/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:33:13 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:32:03 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_mgmt.h"
#ifndef STDDEF_H
# include <stddef.h>
#endif

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (s1 && s2)
		if (ft_strncmp(s1, s2, n) == 0)
			return (1);
	return (0);
}
