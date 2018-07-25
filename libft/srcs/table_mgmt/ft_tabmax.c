/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:01:12 by pde-rent          #+#    #+#             */
/*   Updated: 2018/02/08 18:22:14 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tabmax(int **tab, int col, int row)
{
	int i;
	int j;
	int max;

	if (!tab)
		return (0);
	i = -1;
	max = tab[0][0];
	while (++i < row)
	{
		j = -1;
		while (++j < col)
			if (tab[i][j] > max)
				max = tab[i][j];
	}
	return (max);
}
