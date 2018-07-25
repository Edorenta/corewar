/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:29:41 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 18:58:32 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_op.h"

int		ft_getns(double x, uint8_t b)
{
	int		i;
	double	y;

	y = ft_dabs(x);
	i = 0;
	while (y != ft_rint(y))
	{
		y *= 10;
		i++;
	}
	return (ft_lldigits((long long)(ft_getfrac(x) * ft_dpow(10, i)), b) + 1);
}
