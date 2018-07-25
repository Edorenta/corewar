/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_witoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 06:16:18 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:17:06 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicode.h"

static	size_t		complex_wc(char *buf, wint_t c)
{
	if (c < 0x800)
	{
		*buf = ((c >> 6) & 0x1F) | 0xC0;
		*++buf = ((c >> 0) & 0x3F) | 0x80;
		return (2);
	}
	else if (c < 0x10000)
	{
		*buf = ((c >> 12) & 0xF) | 0xE0;
		*++buf = ((c >> 6) & 0x3F) | 0x80;
		*++buf = ((c >> 0) & 0x3F) | 0x80;
		return (3);
	}
	else if (c < 0x110000)
	{
		*buf = ((c >> 18) & 0x7) | 0xF0;
		*++buf = ((c >> 12) & 0x3F) | 0x80;
		*++buf = ((c >> 6) & 0x3F) | 0x80;
		*++buf = ((c >> 0) & 0x3F) | 0x80;
		return (4);
	}
	return (0);
}

size_t				ft_witoa(char *buf, wint_t c)
{
	if (c < 0x80)
	{
		*buf = (c & 0x7f);
		return (1);
	}
	return (complex_wc(buf, c));
}
