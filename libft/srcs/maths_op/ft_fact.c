/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fact.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:29:28 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 18:58:28 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_ifact(int nb)
{
	if (nb >= 0 && nb < 13)
		return ((nb == 1 || nb == 0) ? 1 : (nb * ft_ifact(nb - 1)));
	return (0);
}

long		ft_lfact(long nb)
{
	return ((nb == 1 || nb == 0) ? 1 : (nb * ft_lfact(nb - 1)));
}

long long	ft_llfact(long long nb)
{
	return ((nb == 1 || nb == 0) ? 1 : (nb * ft_llfact(nb - 1)));
}

double		ft_dfact(double nb)
{
	return ((nb == 1 || nb == 0) ? 1 : (nb * ft_dfact(nb - 1)));
}
