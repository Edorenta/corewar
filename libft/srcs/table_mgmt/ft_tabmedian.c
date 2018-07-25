/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmedian.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:09:25 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:12:17 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_mgmt.h"

static	int		get_median(int **tab, int col, int row, int z)
{
	int	i;
	int j;
	int k;
	int tmp[z];

	if (!tab)
		return (0);
	i = -1;
	k = -1;
	while (++i < col)
	{
		j = -1;
		while (++j < row)
			tmp[++k] = tab[i][j];
	}
	return (ft_arraymedian(&tmp[0], z));
}

int				ft_tabmedian(int **tab, int col, int row)
{
	return (get_median(tab, col, row, col * row));
}
