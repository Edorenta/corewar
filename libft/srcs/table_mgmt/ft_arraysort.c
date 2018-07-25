/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraysort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:30:15 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:40:37 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_mgmt.h"
#include "memory_mgmt.h"
#include "maths_op.h"

static	int		swapper(int *tab, int first, int last)
{
	int pivot;
	int i;
	int j;

	i = (first - 1);
	j = i;
	pivot = tab[last];
	while (++j < last)
		if (tab[j] <= pivot)
			ft_swap(&tab[++i], &tab[j]);
	ft_swap(&tab[i + 1], &tab[last]);
	return (i + 1);
}

static	void	quick_sort(int *tab, int first, int last)
{
	int pivot;

	if (first < last)
	{
		pivot = swapper(tab, first, last);
		quick_sort(tab, first, pivot - 1);
		quick_sort(tab, pivot + 1, last);
	}
}

void			ft_arraysort(int *tab, int first, int last, int dir)
{
	if (tab && last)
		if (ft_iabs(dir) == 1)
			quick_sort(tab, first, last);
	if (dir == -1)
		ft_arrayrev(tab, first, last);
}
