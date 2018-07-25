/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 21:18:17 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/25 21:21:30 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output_mgmt.h"

void	ft_putnbr_base(int n, uint8_t base)
{
	if (base == 10 && n < 0)
		ft_putchar('-');
	if ((n = (n < 0 ? -n : n)) >= base)
		ft_putnbr_base(n / base, base);
	ft_putchar(BASE_LCASE[n % base]);
}
