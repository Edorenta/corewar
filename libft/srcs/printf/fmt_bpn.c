/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_bpn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:16:43 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/04 20:52:58 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** b: printf uint in binary format (base 2)
*/

int		fmt_b(t_modifier *mod, t_array *d, va_list ap)
{
	if (mod->flag.pad.hash)
		fta_append(d, "b", 1);
	return (fmt_uint(mod, d, ap, 2));
}

/*
** p: prints the address that the variable points to on memory
*/

int		fmt_p(t_modifier *mod, t_array *d, va_list ap)
{
	(void)mod;
	fta_append(d, "0x", 2);
	mod->length = 'L';
	return (fmt_uint(mod, d, ap, 16));
}

/*
** n: prints nothing, but writes the number of characters
** successfully written so far into an integer pointer parameter
*/

int		fmt_n(t_modifier *mod, t_array *d, va_list ap)
{
	int		*arg;

	arg = va_arg(ap, void *);
	mod->size = 0;
	mod->precision = -1;
	if (mod->length == 'H')
		*(char *)arg = (char)d->size;
	else if (mod->length == 'h')
		*(short *)arg = (short)d->size;
	else if (mod->length == 'l' || mod->length == 'z')
		*(long *)arg = (long)d->size;
	else if (mod->length == 'L')
		*(long long *)arg = (long long)d->size;
	else if (mod->length == 'j')
		*(intmax_t *)arg = (intmax_t)d->size;
	else
		*(int *)arg = (int)d->size;
	return (0);
}
