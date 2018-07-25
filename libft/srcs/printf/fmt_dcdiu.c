/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_diu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:16:43 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/04 20:52:58 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** d/i: prints an int as is
*/

int			fmt_di(t_modifier *mod, t_array *sstr, va_list ap)
{
	return (fmt_int(mod, sstr, ap, 10));
}

/*
** fmt_int takes the output of all non-fractionnal signed formats as input
** and passes it to the converter (fta_itoa_base) with the right width
*/

int			fmt_int(t_modifier *mod, t_array *sstr, va_list ap, int b)
{
	intmax_t		arg;

	if (mod->length == 'H')
		arg = (signed char)va_arg(ap, int);
	else if (mod->length == 'h')
		arg = (short)va_arg(ap, int);
	else if (mod->length == 'l' || mod->length == 'z')
		arg = va_arg(ap, long);
	else if (mod->length == 'L')
		arg = va_arg(ap, long long);
	else if (mod->length == 'j')
		arg = va_arg(ap, intmax_t);
	else
		arg = va_arg(ap, int);
	if (arg < 0)
		fta_append(sstr, "-", 1);
	else if (mod->flag.pad.plus)
		fta_append(sstr, "+", 1);
	else if (mod->flag.pad.space)
		fta_append(sstr, " ", 1);
	if (arg == 0 && mod->precision == 0)
		return (0);
	return (fta_itoa_base(sstr, arg, ABS(b), b < 0));
}

/*
** fmt_uint takes the output of all non-fractionnal unsigned formats as input
** and passes it to the converter (fta_itoa_base) with the right width
*/

int			fmt_uint(t_modifier *mod, t_array *sstr, va_list ap, int b)
{
	uintmax_t	arg;

	if (mod->length == 'H')
		arg = (unsigned char)va_arg(ap, unsigned);
	else if (mod->length == 'h')
		arg = (unsigned short)va_arg(ap, unsigned);
	else if (mod->length == 'l')
		arg = va_arg(ap, unsigned long);
	else if (mod->length == 'L')
		arg = va_arg(ap, unsigned long long);
	else if (mod->length == 'z')
		arg = va_arg(ap, size_t);
	else if (mod->length == 'j')
		arg = va_arg(ap, uintmax_t);
	else
		arg = va_arg(ap, unsigned);
	if (arg == 0 && mod->flag.pad.hash
		&& (mod->conversion == 'x' || mod->conversion == 'X'))
		sstr->size -= 2;
	if (arg == 0 && mod->precision == 0)
		return (0);
	if (arg == 0 && mod->flag.pad.hash && mod->conversion == 'o')
		sstr->size -= 1;
	return (fta_itoa_base(sstr, arg, ABS(b), 2 | (b < 0)));
}
