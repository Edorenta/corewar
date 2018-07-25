/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdigits.c                                        :+:      :+:    :+:   */
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

int		ft_idigits(int x, uint8_t b)
{
	return (ft_iabs(x) < (int)b ? 0 : (1 + (ft_idigits((x / (int)b), b))));
}

int		ft_ldigits(long x, uint8_t b)
{
	return (ft_labs(x) < (long)b ? 0 : (1 + (ft_ldigits((x / (long)b), b))));
}

int		ft_lldigits(long long x, uint8_t b)
{
	return (ft_llabs(x) < (long long)b ? 0
			: (1 + (ft_lldigits((x / (long long)b), b))));
}

int		ft_ddigits(double x, uint8_t b)
{
	return (ft_dabs(x) < (double)b ? 0
			: (1 + (ft_ddigits((x / (double)b), b))));
}
