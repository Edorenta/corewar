/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 15:10:35 by pde-rent          #+#    #+#             */
/*   Updated: 2017/05/17 09:17:59 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_mgmt.h"
#include "output_mgmt.h"
#ifndef STDLIB_H
# include <stdlib.h>
#endif

void	ft_exit(const char *const fnc, const char *const str)
{
	ft_putstr_fd("ERROR\tCritical failure in function ", 2);
	ft_putstr_fd(fnc, 2);
	ft_putstr_fd(". The program will exit, reason being : ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(".\n", 2);
	exit(1);
}
