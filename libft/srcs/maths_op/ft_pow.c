/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:10:27 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 18:58:37 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDINT_H
# include <stdint.h>
#endif

int			ft_ipow(int a, uint8_t power)
{
	int ret;

	ret = 1;
	while (power > 0)
	{
		if (power & 1)
			ret *= a;
		a *= a;
		power >>= 1;
	}
	return (ret);
}

long		ft_lpow(long a, uint8_t power)
{
	long ret;

	ret = 1;
	while (power > 0)
	{
		if (power & 1)
			ret *= a;
		a *= a;
		power >>= 1;
	}
	return (ret);
}

long long	ft_llpow(long long a, uint8_t power)
{
	long long ret;

	ret = 1;
	while (power > 0)
	{
		if (power & 1)
			ret *= a;
		a *= a;
		power >>= 1;
	}
	return (ret);
}

double		ft_dpow(double a, uint8_t power)
{
	double ret;

	ret = 1;
	while (power > 0)
	{
		if (power & 1)
			ret *= a;
		a *= a;
		power >>= 1;
	}
	return (ret);
}
