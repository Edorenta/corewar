/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 12:39:02 by pde-rent          #+#    #+#             */
/*   Updated: 2017/01/13 13:53:56 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_op.h"
#include "char_class.h"

double	ft_atof(const char *str)
{
	long long	nb;
	int			sign;
	int			digits;

	nb = 0;
	if (!str)
		return (0);
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	digits = (*str == '.') ? 1 : 0;
	str = ((*str == '.' || *str == '-' || *str == '+') ? ++str : str);
	while (ft_isdigit(*str))
	{
		digits = (digits ? ++digits : digits);
		nb = nb * 10 + (*str++ - 48);
		if (*str == '.')
		{
			if (digits)
				break ;
			digits = 1;
			str++;
		}
	}
	return (((double)sign * ((double)nb / (double)ft_llpow(10, digits - 1))));
}
