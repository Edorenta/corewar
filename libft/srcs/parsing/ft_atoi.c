/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 12:39:02 by pde-rent          #+#    #+#             */
/*   Updated: 2017/01/13 13:53:56 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char_class.h"

int				ft_atoi(const char *str)
{
	int		nb;
	int		sign;

	while (ft_isspace(*str))
		++str;
	sign = *str == '-' ? -1 : 1;
	if (*str == '+' || *str == '-')
		++str;
	nb = 0;
	while (ft_isdigit(*str))
		nb = 10 * nb + sign * (*str++ - '0');
	return (nb);
}

long			ft_atol(const char *str)
{
	long		nb;
	long		sign;

	while (ft_isspace(*str))
		++str;
	sign = *str == '-' ? -1 : 1;
	if (*str == '+' || *str == '-')
		++str;
	nb = 0;
	while (ft_isdigit(*str))
		nb = 10 * nb + sign * (*str++ - '0');
	return (nb);
}

long long		ft_atoll(const char *str)
{
	long long		nb;
	long long		sign;

	while (ft_isspace(*str))
		++str;
	sign = *str == '-' ? -1 : 1;
	if (*str == '+' || *str == '-')
		++str;
	nb = 0;
	while (ft_isdigit(*str))
		nb = 10 * nb + sign * (*str++ - '0');
	return (nb);
}
