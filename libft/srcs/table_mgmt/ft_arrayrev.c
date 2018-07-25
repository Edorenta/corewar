/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayrev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:30:12 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:50:32 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_arrayrev(int *tab, int start, int end)
{
	int tmp;

	if (tab)
		while (start < end)
		{
			tmp = tab[start];
			tab[start++] = tab[end];
			tab[end--] = tmp;
		}
}
