/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:59:21 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/19 18:57:38 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_op.h"

double		ft_roundec(double x, uint8_t dec)
{
	double	fact;

	fact = ft_dpow(10, dec);
	x *= fact;
	x = ft_rint(x);
	return (x /= fact);
}

double		ft_roundig(double x, uint8_t dig)
{
	double	fact;

	fact = ft_dpow(10, dig);
	x /= fact;
	x = ft_rint(x);
	return (x *= fact);
}
