/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdecimals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:10:27 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 18:58:52 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_op.h"
#ifndef STDINT_H
# include <stdint.h>
#endif

int		adj_zeros(double n)
{
	int i;

	i = -1;
	n = ft_dabs(n) - ft_floor(ft_dabs(n));
	while (n <= 1.0 && ++i > -1)
		n *= 10.0;
	return (i);
}

int		fwd_zeros(double n)
{
	int i;

	i = -1;
	n = (long long)(n);
	while (++i > -1 && n == ft_roundig(n, 1))
		n /= 10.0;
	return (i);
}

int		ft_decimals(double x, uint8_t b)
{
	int		i;
	double	y;

	y = ft_dabs(x);
	i = 0;
	while (y != ft_rint(y))
	{
		y = ft_roundec(y, 10);
		y *= 10;
		i++;
	}
	return (ft_ddigits((ft_getfrac(x) * ft_dpow(10, i)), b) + adj_zeros(x) + 1);
}
