/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:29:41 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 18:58:32 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIMITS_H
# include <limits.h>
#endif

double	ft_floor(double x)
{
	long long	n;
	double		d;

	n = (long long)x;
	d = (double)n;
	if (x >= LLONG_MAX || x <= LLONG_MIN || x != x)
		return (x);
	if (d == x || x >= 0)
		return (d);
	return (d - 1);
}
