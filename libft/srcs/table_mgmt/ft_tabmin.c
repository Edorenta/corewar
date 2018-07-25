/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:04:29 by pde-rent          #+#    #+#             */
/*   Updated: 2018/02/08 18:21:56 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tabmin(int **tab, int col, int row)
{
	int i;
	int j;
	int min;

	if (!tab)
		return (0);
	i = -1;
	min = tab[0][0];
	while (++i < row)
	{
		j = -1;
		while (++j < col)
			if (tab[i][j] < min)
				min = tab[i][j];
	}
	return (min);
}
