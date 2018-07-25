/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:30:08 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/16 16:16:56 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output_mgmt.h"

void	ft_arrayprint(int *tab, int n, char sep)
{
	int i;

	i = -1;
	if (tab && n)
		while (++i < n)
		{
			ft_putnbr(tab[i]);
			if (i < (n - 1))
				ft_putchar(sep);
		}
}
