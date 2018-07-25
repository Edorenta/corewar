/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:05:24 by pde-rent          #+#    #+#             */
/*   Updated: 2018/02/08 18:21:43 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tabmean(int **tab, int col, int row)
{
	int i;
	int j;
	int sum;

	if (!tab)
		return (0);
	i = -1;
	sum = 0;
	while (++i < row)
	{
		j = -1;
		while (++j < col)
			sum += tab[i][j];
	}
	return (sum / (col * row));
}
