/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_eEgG.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:16:43 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/04 20:52:58 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** e : prints double value in standard scientific notation ([-]d.ddd e[+/-]ddd)
*/

int			fmt_e(t_modifier *mod, t_array *sstr, va_list ap)
{
	return (fmt_ns_float(mod, sstr, ap, 10));
}

/*
** E : prints double value in standard scientific notation ([-]d.ddd E[+/-]ddd)
*/

int			fmt_ce(t_modifier *mod, t_array *sstr, va_list ap)
{
	return (fmt_ns_float(mod, sstr, ap, -10));
}

/*
** g : double in either normal or exponential notation,
** whichever is more appropriate for its magnitude using lower case letters
*/

int			fmt_g(t_modifier *mod, t_array *sstr, va_list ap)
{
	return (fmt_g_float(mod, sstr, ap, 10));
}

/*
** G : double in either normal or exponential notation,
** whichever is more appropriate for its magnitude using upper case letters
*/

int			fmt_cg(t_modifier *mod, t_array *sstr, va_list ap)
{
	return (fmt_g_float(mod, sstr, ap, -10));
}
