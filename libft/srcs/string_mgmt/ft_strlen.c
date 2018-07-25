/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 00:41:05 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/25 12:13:17 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDDEF_H
# include <stddef.h>
#endif

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
