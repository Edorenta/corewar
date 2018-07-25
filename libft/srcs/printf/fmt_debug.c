/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 11:25:39 by pde-rent          #+#    #+#             */
/*   Updated: 2017/03/21 13:34:41 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** prints a bool value
*/

void	debug_put_bool(char c)
{
	ft_putstr(c ? "true" : "false");
	return ;
}

/*
** prints the whole content of the modifier structure
*/

void	debug_put_modifier(t_modifier *mod)
{
	size_t		n;

	ft_putstr("(t_modifier){\n\t{");
	n = 6;
	while (n-- > 0)
	{
		ft_putstr("\n\t\t");
		debug_put_bool(mod->flag.t[5 - n]);
	}
	ft_putstr("\n\t}\n\t'");
	ft_putchar(mod->conversion);
	ft_putstr("'\n\t'");
	ft_putchar(mod->length);
	ft_putstr("'\n\t");
	ft_putnbr(mod->size);
	ft_putstr("\n\t");
	ft_putnbr(mod->precision);
	ft_putstr("\n}\n");
	return ;
}
