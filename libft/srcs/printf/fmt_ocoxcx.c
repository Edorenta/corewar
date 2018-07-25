/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_oOxX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:16:43 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/04 20:52:58 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** u: uint conversion (base 10)
*/

int		fmt_u(t_modifier *mod, t_array *sstr, va_list ap)
{
	return (fmt_uint(mod, sstr, ap, 10));
}

/*
** o: uint octal conversion (base 8)
*/

int		fmt_o(t_modifier *mod, t_array *sstr, va_list ap)
{
	if (mod->flag.pad.hash)
		fta_append(sstr, "0", 1);
	return (fmt_uint(mod, sstr, ap, 8));
}

/*
** x: lower case uint hexadecimal conversion (base 16)
*/

int		fmt_x(t_modifier *mod, t_array *sstr, va_list ap)
{
	if (mod->flag.pad.hash)
		fta_append(sstr, "0x", 2);
	return (fmt_uint(mod, sstr, ap, 16));
}

/*
** X: upper case uint hexadecimal conversion (base 16)
*/

int		fmt_cx(t_modifier *mod, t_array *sstr, va_list ap)
{
	if (mod->flag.pad.hash)
		fta_append(sstr, "0X", 2);
	return (fmt_uint(mod, sstr, ap, -16));
}
