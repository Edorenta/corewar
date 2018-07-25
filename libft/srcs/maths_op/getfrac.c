/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getfrac.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:10:27 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 18:58:57 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_op.h"

double		ft_getfrac(double x)
{
	return (ft_dabs(x) - ft_floor(ft_dabs(x)));
}

double		ft_getmantissa(double x)
{
	return (ft_getfrac(x));
}
