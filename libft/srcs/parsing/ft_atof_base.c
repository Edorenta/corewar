/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 12:39:02 by pde-rent          #+#    #+#             */
/*   Updated: 2017/01/13 13:53:56 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_op.h"
#include "char_class.h"

static inline	int		in_base(char c, uint8_t base)
{
	if (base <= 10 && (c >= '0' && c <= '9'))
		return (1);
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)));
}

double					ft_atof_base(const char *str, uint8_t base)
{
	long long	nb;
	int			sign;
	int			digits;

	if (base <= 1 || base > 36 || !str)
		return (0);
	while (ft_isspace(*str) && (nb = 0))
		str++;
	sign = (*str == '-') ? -1 : 1;
	digits = (*str == '.') ? 1 : 0;
	str = ((*str == '.' || *str == '-' || *str == '+') ? ++str : str);
	while (in_base(*str, base))
	{
		digits = (digits ? ++digits : digits);
		nb = ((*str - 'A' >= 0) ? (nb * base + (*str - 'A' + 10))
				: nb * base + (*str++ - '0'));
		if (*str == '.')
		{
			if (digits)
				break ;
			digits = 1;
			str++;
		}
	}
	return (((double)sign * ((double)nb / (double)ft_llpow(base, digits - 1))));
}
