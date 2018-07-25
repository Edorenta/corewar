/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:59:21 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/19 18:57:38 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_op.h"

double	ft_rint(double x)
{
	double			ret;
	const double	two_p_52 = 4.5035996273704960e+15;

	ret = two_p_52 + ft_dabs(x);
	if (ft_dabs(x) >= two_p_52)
		ret = x;
	else
	{
		ret -= two_p_52;
		ret = ft_copysign(ret, x);
	}
	return (ret);
}

float	ft_rintf(float x)
{
	float			ret;
	const float		two_p_52 = 4.5035996273704960e+15f;

	ret = two_p_52 + ft_dabs(x);
	if (ft_dabs(x) >= two_p_52)
		ret = x;
	else
	{
		ret -= two_p_52;
		ret = ft_copysign(ret, x);
	}
	return (ret);
}
