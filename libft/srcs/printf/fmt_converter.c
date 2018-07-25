/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:16:43 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/23 14:21:54 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** fta_itoa_base appends "n" expressed in base "b" onto the string "sstr"
** if the first bit of "mask" is on, capital letters will be used
** for alphadecimal bases (greater than base 10)
** the above achieved by passing bases as negative values to the function
** if the second bit of "mask" is on, "n" is considered unsigned
*/

int				fta_itoa_base(t_array *sstr, intmax_t n,
						int b, char mask)
{
	int					ret;
	const uintmax_t		un = (uintmax_t)n;
	const char			*base =

	(mask & 1 ? BASE_UCASE : BASE_LCASE);
	ret = 1;
	if (mask & 2 ? (uintmax_t)b <= un : n <= -b || b <= n)
		ret += fta_itoa_base(sstr, (mask & 2 ?
			(intmax_t)(un / b) : n / b), b, mask);
	fta_append(sstr, (void *)(base +
		(mask & 2 ? (size_t)(un % b) : ABS(n % b))), 1);
	return (ret);
}

/*
** int						fta_itoa_base(t_array *sstr, intmax_t n,
** 								int b, char mask)
** {
** 	ft_bzero(tmp, 100);
** 	ft_strcpy(tmp, fta_lltoa_base(ft_llabs(n), b, mask));
** 	fta_append(sstr, (void *)tmp, ft_strlen(tmp));
** 	return (ft_strlen(tmp));
** }
*/

/*
** special check for floating point limits infinity and NaNs (f/F)
*/

int				check_extrema(t_array *sstr, long double n, char mask)
{
	if (ft_isinf(n))
	{
		if (mask & 1)
			fta_append(sstr, "INFINITY", 8);
		else
			fta_append(sstr, "infinity", 8);
		return (1 + 8);
	}
	if (ft_isnan(n))
	{
		if (mask & 1)
			fta_append(sstr, "NAN", 3);
		else
			fta_append(sstr, "nan", 3);
		return (4);
	}
	return (0);
}

/*
** fta_dtoa_base appends "n" expressed in base "b" onto the string "sstr"
** if the first bit of "mask" is on, capital letters will be used
** for alphadecimal bases (greater than base 10) and NAN/INF returns
** if the second bit of "mask" is on, "n" is considered unsigned
** this is achieved by passing bases as negative values to the function
*/

int				fta_dtoa_base(t_array *sstr, long double n,
						char mask, t_modifier *mod)
{
	char	*tmp;
	int		i;

	if ((i = check_extrema(sstr, n, mask)))
		return (i);
	tmp = fta_ftoa_base(ft_dabs(n), mod->base, mod->precision, mask);
	fta_append(sstr, (void *)tmp, ft_strlen(tmp));
	i = ft_strlen(tmp);
	free(tmp);
	return (i);
}

/*
** same but including scientific notation
*/

int				fta_dtoa_ns(t_array *sstr, long double n, char mask,
						t_modifier *mod)
{
	char	*tmp;
	int		i;

	if ((i = check_extrema(sstr, n, mask)))
		return (i);
	tmp = fta_ftoa_ns(ft_dabs(n), mod->precision, mask);
	fta_append(sstr, (void *)tmp, ft_strlen(tmp));
	i = ft_strlen(tmp);
	free(tmp);
	return (i);
}
