/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:37:29 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:08:57 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_op.h"
#include "parsing.h"
#ifndef STDLIB_H
# include <stdlib.h>
#endif

char	*ft_itoa_base(int n, uint8_t base)
{
	return (ft_ltoa_base((long)n, base));
}

char	*ft_ltoa_base(long n, uint8_t base)
{
	long	tmp1;
	long	tmp2;
	int		digits;
	int		i;
	char	*str;

	tmp1 = ft_labs((long)n);
	digits = ft_ldigits(tmp1, base);
	i = ((n < 0 && base == 10) ? 1 : 0) + digits;
	if (!(str = (char *)malloc(sizeof(char) * i + 2)))
		return ((void *)0);
	i = -1;
	if ((n < 0 && base == 10))
		str[++i] = '-';
	while (digits)
	{
		tmp2 = tmp1 / ft_lpow(base, digits);
		str[++i] = BASE_LCASE[tmp2];
		tmp1 -= (tmp2 * ft_lpow(base, digits));
		digits--;
	}
	str[++i] = BASE_LCASE[tmp1];
	str[++i] = '\0';
	return (str);
}

char	*ft_lltoa_base(long long n, uint8_t base)
{
	long long	tmp1;
	long long	tmp2;
	int			digits;
	int			i;
	char		*str;

	tmp1 = ft_labs((long long)n);
	digits = ft_ldigits(tmp1, base);
	i = ((n < 0 && base == 10) ? 1 : 0) + digits;
	if (!(str = (char *)malloc(sizeof(char) * i + 2)))
		return ((void *)0);
	i = -1;
	if ((n < 0 && base == 10))
		str[++i] = '-';
	while (digits)
	{
		tmp2 = tmp1 / ft_llpow(base, digits);
		str[++i] = BASE_LCASE[tmp2];
		tmp1 -= (tmp2 * ft_llpow(base, digits));
		digits--;
	}
	str[++i] = BASE_LCASE[tmp1];
	str[++i] = '\0';
	return (str);
}
