/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnconv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 06:16:18 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:19:15 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicode.h"

size_t		ft_wstrnconv(char *buff, const wchar_t *wstr, size_t n)
{
	size_t	ret;
	size_t	tmp;

	ret = 0;
	tmp = 0;
	while (*wstr != 0)
	{
		tmp = ft_witoa(buff + ret, (wint_t) * (wstr++));
		if (ret + tmp > n)
			break ;
		ret += tmp;
	}
	return (ret);
}
