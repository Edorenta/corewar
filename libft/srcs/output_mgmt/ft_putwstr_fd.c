/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 06:16:18 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:07:56 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output_mgmt.h"

void		ft_putwstr_fd(const wchar_t *wstr, int fd)
{
	int		i;

	i = -1;
	while (wstr[++i])
		ft_putwchar_fd(wstr[i], fd);
}
