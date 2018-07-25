/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:16:43 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/23 15:23:32 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void		ns_float_trim(char *str)
{
	char	tmp[100];
	char	*ptr;
	char	*ptr2;

	ft_bzero(tmp, 100);
	ptr = ft_strpbrk(str, "Ee");
	ptr2 = &tmp[0];
	while (*ptr == '0' && (*(--ptr)) == '0')
		*ptr = 32;
	ptr = str;
	while (*ptr && *ptr2)
	{
		if (*ptr != 32)
			*ptr2++ = *ptr++;
		if (!*(++ptr))
			break ;
	}
}

static inline void		b_float_trim(char *str)
{
	char	tmp[100];
	char	*ptr;
	char	*ptr2;

	ft_bzero(tmp, 100);
	ptr = str + ft_strlen(str);
	ptr2 = &tmp[0];
	if (is_in('.', str))
		while (*(--ptr) == '0')
			*ptr = '\0';
}

int						fmt_ns_float(t_modifier *mod, t_array *sstr,
								va_list ap, int b)
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
	return (fta_dtoa_ns(sstr, arg, b < 0, mod));
}

int						fmt_g_float(t_modifier *mod, t_array *sstr,
								va_list ap, int b)
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
	return (fta_dtoa_g(sstr, arg, b < 0, mod));
}

int						fta_dtoa_g(t_array *sstr, long double n,
								char mask, t_modifier *mod)
{
	char	*tmp;
	int		i;

	if ((i = check_extrema(sstr, n, mask)))
		return (i);
	if (ft_dabs(n) >= 1000000.0 || ft_dabs(n) < 0.0001)
	{
		tmp = fta_ftoa_ns(ft_dabs(n), mod->precision, mask);
		ns_float_trim(tmp);
	}
	else
	{
		tmp = fta_ftoa_base(ft_dabs(n), 10, mod->precision, mask);
		b_float_trim(tmp);
	}
	fta_append(sstr, (void *)tmp, ft_strlen(tmp));
	i = ft_strlen(tmp);
	free(tmp);
	return (i);
}
