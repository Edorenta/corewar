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

#include "string_mgmt.h"
#include "maths_op.h"
#include "parsing.h"
#include "memory_mgmt.h"
#include "char_class.h"
#include "private_macros.h"

#define MAX_ACCURACY 15

static inline char	*add_exp_ns(t_ftoa_ns *ftoa, char *ptr, uint8_t precision,
							char mask)
{
	int		i;
	char	*tmp;

	precision = MIN(precision, 7);
	i = ftoa->neg ? 1 : 0 + precision;
	tmp = ft_isdigit(ptr[i + 1]) ? ptr + i + 1 : ptr + i + 2;
	ptr[i] = *tmp < '5' ? ptr[i] : ptr[i] + 1;
	ptr[++i] = (mask & 1) ? 'E' : 'e';
	ptr[++i] = (ftoa->exp < 0 ? '-' : '+');
	ptr[++i] = (ftoa->exp > 9 ? '\0' : '0');
	ptr[++i] = '\0';
	ft_strcat(ptr, ft_itoa(ft_iabs(ftoa->exp)));
	return (ft_strdup(ptr));
}

static inline void	ftoa_ns_init(t_ftoa_ns *ftoa, double n,
							char *tmp1, char *tmp2)
{
	ft_bzero(tmp1, 100);
	ft_bzero(tmp2, 100);
	ftoa->neg = n < 0 ? '-' : '\0';
	ftoa->exp = ft_getexp(n);
}

char				*fta_ftoa_ns(double n, uint8_t precision, char mask)
{
	t_ftoa_ns	ftoa;
	char		tmp[2][100];
	char		*ptr[2];

	ftoa_ns_init(&ftoa, n, &(tmp[0][0]), &(tmp[1][0]));
	ft_strcpy(tmp[0], ft_ftoa_base(n, 10, MAX_ACCURACY));
	ptr[0] = ft_strpbrk(tmp[0], "123456789");
	ptr[1] = tmp[1];
	if (ftoa.neg)
	{
		*ptr[1] = '-';
		*(++ptr[1]) = *ptr[0]++;
		*(++ptr[1]) = '.';
	}
	else
	{
		*ptr[1] = *ptr[0] == '.' ? *(++ptr[0]) : *ptr[0]++;
		*(++ptr[1]) = '.';
	}
	while (*ptr[0] && *ptr[1])
	{
		ptr[0] = *ptr[0] == '.' ? ++ptr[0] : ptr[0];
		*(++ptr[1]) = *ptr[0]++;
	}
	return (add_exp_ns(&ftoa, &(tmp[1][0]), precision, mask));
}
