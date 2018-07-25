/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:43:41 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/25 17:48:17 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output_mgmt.h"

void	ft_putstr(const char *str)
{
	const char *ptr = str;

	while (*ptr != '\0')
		++ptr;
	write(1, str, ptr - str);
}
