/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 06:16:18 by pde-rent          #+#    #+#             */
/*   Updated: 2017/09/22 21:06:28 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output_mgmt.h"
#include "unicode.h"

void	ft_putwchar(wchar_t c)
{
	char	buf[4];
	int		n;

	n = ft_witoa(&buf[0], c);
	ft_putstr(buf);
}
