/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forceput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:54:23 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:06:50 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output_mgmt.h"
#include "char_class.h"
#include "non_printables.h"

static inline void	print_non_printable(char c)
{
	char	tmp[6];

	tmp[0] = '[';
	tmp[1] = NON_PRINT[c * 3];
	tmp[2] = NON_PRINT[c * 3 + 1];
	tmp[3] = NON_PRINT[c * 3 + 2] ? NON_PRINT[c * 3 + 2] : ']';
	tmp[4] = NON_PRINT[c * 3 + 2] ? ']' : '\0';
	tmp[5] = '\0';
	ft_putstr(tmp);
}

void				ft_forceput(char c)
{
	if (ft_isprint(c))
		ft_putchar(c);
	else if (c >= 0 && c < 32)
		print_non_printable(c);
	else
		ft_putstr("[non ascii char]");
}
