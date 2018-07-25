/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:43:41 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:06:30 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output_mgmt.h"

void	ft_putnstr(const char *str, size_t n)
{
	const char *ptr = str;

	while (*ptr != '\0')
		++ptr;
	n = (size_t)(ptr - str) > n ? n : (size_t)(ptr - str);
	write(1, str, n);
}
