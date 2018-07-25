/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_aA.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:16:43 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/04 20:52:58 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** a: float hexadecimal conversion (base 16) starting with "0x"
*/

int			fmt_a(t_modifier *mod, t_array *sstr, va_list ap)
{
	if (mod->flag.pad.hash)
		fta_append(sstr, "0x", 2);
	return (fmt_float(mod, sstr, ap, 16));
}

/*
** A: float hexadecimal conversion (base 16) starting with "0X"
*/

int			fmt_ca(t_modifier *mod, t_array *sstr, va_list ap)
{
	if (mod->flag.pad.hash)
		fta_append(sstr, "0X", 2);
	return (fmt_float(mod, sstr, ap, -16));
}
