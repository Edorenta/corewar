/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_ns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:02:33 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:46:03 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_mgmt.h"
#include "maths_op.h"
#include "parsing.h"
#include "memory_mgmt.h"

#define MAX_ACCURACY 15

static inline char	*add_exp_ns(t_ftoa_ns *ftoa, char *ptr)
{
	int	i;

	i = 7 + (ftoa->neg ? 1 : 0);
	ptr[i] = ptr[i + 1] < '5' ? ptr[i] : ptr[i] + 1;
	ptr[++i] = 'e';
	ptr[++i] = (ftoa->exp < 0 ? '-' : '+');
	ptr[++i] = (ftoa->exp > 9 ? '\0' : '0');
	ptr[++i] = '\0';
	ft_strcat(ptr, ft_itoa(ft_iabs(ftoa->exp)));
	return (ft_strdup(ptr));
}

static inline void	ftoa_ns_init(t_ftoa_ns *ftoa, double n,
							char *tmp, char *ptr)
{
	ft_strcpy(tmp, ft_ftoa_base(n, 10, MAX_ACCURACY));
	ptr = ft_strpbrk(&tmp[0], "123456789");
	ftoa->neg = n < 0 ? '-' : '\0';
	ftoa->exp = ft_getexp(n);
}

char				*ft_ftoa_ns(double n)
{
	t_ftoa_ns	ftoa;
	char		tmp[2][100];
	char		*ptr[2];

	ftoa_ns_init(&ftoa, n, tmp[0], ptr[0]);
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
	return (add_exp_ns(&ftoa, &(tmp[1][0])));
}
