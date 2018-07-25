/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getwhole.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:10:27 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 18:59:08 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_op.h"

int			ft_geti(double x)
{
	return ((int)ft_floor(x));
}

long		ft_getl(double x)
{
	return ((long)ft_floor(x));
}

long long	ft_getll(double x)
{
	return ((long long)ft_floor(x));
}
