/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:43:41 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 18:09:14 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output_mgmt.h"

void	ft_putnstr_fd(const char *str, int fd, size_t n)
{
	const char *ptr = str;

	while (*ptr != '\0')
		++ptr;
	n = (size_t)(ptr - str) > n ? n : (size_t)(ptr - str);
	write(fd, str, n);
}
