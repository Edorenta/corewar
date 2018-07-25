/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:29:19 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:09:13 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char_class.h"
#ifndef STDINT_H
# include <stdint.h>
#endif

static inline int		in_base(char c, uint8_t base)
{
	if (base <= 10 && (c >= '0' && c <= '9'))
		return (1);
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)));
}

int						ft_atoi_base(const char *str, uint8_t base)
{
	int	nb;
	int	sign;

	nb = 0;
	if (base <= 1 || base > 36 || !str)
		return (0);
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (in_base(*str, base))
	{
		nb = ((*str - 'A' >= 0) ? (nb * base + (*str - 'A' + 10))
				: nb * base + (*str - '0'));
		str++;
	}
	return (nb * sign);
}

long					ft_atol_base(const char *str, uint8_t base)
{
	long	nb;
	long	sign;

	nb = 0;
	if (base <= 1 || base > 36 || !str)
		return (0);
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (in_base(*str, base))
	{
		nb = ((*str - 'A' >= 0) ? (nb * base + (*str - 'A' + 10))
				: nb * base + (*str - '0'));
		str++;
	}
	return (nb * sign);
}

long long				ft_atoll_base(const char *str, uint8_t base)
{
	long long	nb;
	long long	sign;

	nb = 0;
	if (base <= 1 || base > 36 || !str)
		return (0);
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (in_base(*str, base))
	{
		nb = ((*str - 'A' >= 0) ? (nb * base + (*str - 'A' + 10))
				: nb * base + (*str - '0'));
		str++;
	}
	return (nb * sign);
}
