/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_fF.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:16:43 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/04 20:52:58 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** f : prints a floating number (float or double) as is using
** lower case for non-standard output (NaN, Infinity)
*/

int			fmt_f(t_modifier *mod, t_array *sstr, va_list ap)
{
	return (fmt_float(mod, sstr, ap, 10));
}

/*
** F : prints a floating number (float or double) as is using
** upper case for non-standard output (NAN, INFINITY)
*/

int			fmt_cf(t_modifier *mod, t_array *sstr, va_list ap)
{
	return (fmt_float(mod, sstr, ap, -10));
}

/*
** fmt_int takes the output of all fractionnal formats as input
** and passes it to the converter (fta_dtoa_base) with the right width
*/

int			fmt_float(t_modifier *mod, t_array *sstr, va_list ap, int b)
{
	long double		arg;

	if (mod->length == 'L')
		arg = va_arg(ap, long double);
	else
		arg = va_arg(ap, double);
	if (arg < 0)
		fta_append(sstr, "-", 1);
	else if (mod->flag.pad.plus)
		fta_append(sstr, "+", 1);
	else if (mod->flag.pad.space)
		fta_append(sstr, " ", 1);
	if (arg == 0 && mod->precision == 0)
		return (0);
	mod->base = ABS(b);
	return (fta_dtoa_base(sstr, arg, b < 0, mod));
}
