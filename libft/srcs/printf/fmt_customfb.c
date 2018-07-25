/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_custom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:37:29 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:08:57 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_op.h"
#include "parsing.h"
#include "char_class.h"
#include "private_macros.h"
#include "memory_mgmt.h"
#include "string_mgmt.h"
#ifndef STDLIB_H
# include <stdlib.h>
#endif

char					*fta_lltoa_base(long long n, uint8_t base, char mask)
{
	long long		tmp[2];
	int				digits;
	int				i;
	char			*str;
	const char		*b =

	(mask & 1 ? BASE_UCASE : BASE_LCASE);
	tmp[0] = ft_labs((long long)n);
	digits = ft_ldigits(tmp[0], base);
	i = ((n < 0 && base == 10) ? 1 : 0) + digits;
	if (!(str = (char *)malloc(sizeof(char) * i + 2)))
		return ((void *)0);
	i = -1;
	if ((n < 0 && base == 10))
		str[++i] = '-';
	while (digits)
	{
		tmp[1] = tmp[0] / ft_llpow(base, digits);
		str[++i] = b[tmp[1]];
		tmp[0] -= (tmp[1] * ft_llpow(base, digits));
		digits--;
	}
	str[++i] = b[tmp[0]];
	str[++i] = '\0';
	return (str);
}

static inline	char	*ftoa_base_trim(t_ftoa_base *ftoa, char *str)
{
	int	i;
	int	j;

	j = ftoa->neg ? 1 : 0;
	if ((int)ftoa->precision < ftoa->dec)
	{
		j += ftoa->dig + ftoa->precision;
		i = !ft_isdigit(str[j]) ? 1 : 0;
		str[j - i] = str[j + 1] >= '5' ? str[j - i] += 1 : str[j - i];
		str[++j - i] = '\0';
	}
	else
	{
		j += ftoa->dig + ftoa->dec;
		while (++j < ((int)ftoa->precision + 1 + ftoa->dig))
			str[j] = '0';
		str[j] = '\0';
	}
	return (str);
}

static inline	char	*ftoa_base_init(t_ftoa_base *ftoa, double n, int *i)
{
	char	*str;

	ftoa->adjz = adj_zeros(n);
	ftoa->whole = ft_getll(ft_dabs(n));
	ftoa->dig = ft_ddigits(n, ftoa->base) + 1;
	ftoa->dec = ft_decimals(n, ftoa->base);
	ftoa->fract = (long long)ft_rint(ft_dpow(10, ftoa->dec)
			* (ft_dabs(n) - ftoa->whole));
	ftoa->neg = n < 0 && ftoa->base == 10 ? 1 : 0;
	*i = (int)ftoa->neg + ftoa->dig
			+ MAX(ftoa->dec, ftoa->precision) + ftoa->adjz;
	if (!(str = (char *)malloc(sizeof(char) * (*i + 2))))
		return ((void *)0);
	ft_bzero(str, *i + 2);
	str[0] = ftoa->neg ? '-' : '\0';
	return (str);
}

char					*fta_ftoa_base(double n, uint8_t base,
								uint8_t precision, char mask)
{
	t_ftoa_base		ftoa;
	char			*str;
	char			*tmp;
	int				i;

	ftoa.base = base;
	ftoa.precision = MIN(6, precision);
	if (!(str = ftoa_base_init(&ftoa, n, &i)))
		return ((void *)0);
	tmp = fta_lltoa_base(ftoa.whole, base, mask);
	ft_strcpy(&str[(int)(ftoa.neg)], tmp);
	free(tmp);
	i = ft_strlen(str);
	str[i] = '.';
	while (ftoa.adjz > 0 && ftoa.adjz--)
		str[++i] = '0';
	tmp = fta_lltoa_base(ftoa.fract, base, mask);
	ft_strncat(&str[++i], tmp, ftoa.precision + 1);
	free(tmp);
	return (ftoa_base_trim(&ftoa, str));
}
