/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:16:43 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/04 20:52:58 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** assigns the right format conversion option to the right flag
** returns the width (after) conversion
*/

static inline int
	conv_call(t_modifier *mod, t_array *sstr, va_list ap)
{
	int			i;
	const char	*fmt = "diuoxXfFeEgGaAcCsSpbrn\0";
	const void	*t[] = {&fmt_di, &fmt_di, &fmt_u, &fmt_o,
			&fmt_x, &fmt_cx, &fmt_f, &fmt_cf, &fmt_e, &fmt_ce,
			&fmt_g, &fmt_cg, &fmt_a, &fmt_ca, &fmt_c, &fmt_wc,
			&fmt_s, &fmt_ws, &fmt_p, &fmt_b, &fmt_r, &fmt_n};

	if (mod->length == 'l' && is_in(mod->conversion, "cs\0") >= 0)
		mod->conversion -= 32;
	if (is_in(mod->conversion, "DOU\0") >= 0)
	{
		mod->conversion += 32;
		mod->length = 'l';
	}
	i = 0;
	while (fmt[i] != '\0' && mod->conversion != fmt[i])
		i++;
	if (fmt[i])
		return (((int (*)())t[i])(mod, sstr, ap));
	fta_append(sstr, &mod->conversion, 1);
	return (1);
}

/*
** assigns the right precision and adjacent zeros
** returns the precision (after) conversion
*/

static inline int
	last_call(t_modifier *mod, t_array *sstr, va_list ap)
{
	size_t	before;
	size_t	after;
	int		width;
	int		len;

	before = sstr->size;
	width = conv_call(mod, sstr, ap);
	after = sstr->size;
	len = width;
	if (len < mod->precision && is_in(mod->conversion, FLAGS_NUM) >= 0)
	{
		while (len < mod->precision && ++len)
			fta_append(sstr, "0", 1);
		fta_swap(sstr, after - width, after);
	}
	return (len);
}

/*
** calls to the functions above, assigning modifiers and filling sstr buffer
*/

void
	convert(t_modifier *mod, t_array *sstr, va_list ap)
{
	size_t	before;
	size_t	after;
	int		width;
	int		len;

	before = sstr->size;
	width = last_call(mod, sstr, ap);
	after = sstr->size;
	len = after - before;
	if (len < mod->size)
	{
		if (mod->flag.pad.zero
			&& mod->precision == -1
			&& !mod->flag.pad.minus)
		{
			while (len < mod->size && ++len)
				fta_append(sstr, "0", 1);
			before = after - width;
		}
		else
			while (len < mod->size && ++len)
				fta_append(sstr, " ", 1);
		if (!mod->flag.pad.minus)
			fta_swap(sstr, before, after);
	}
}
