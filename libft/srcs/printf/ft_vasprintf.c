/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:16:43 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/04 20:52:58 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ptr_atoi writes its output value on *ret and is aware for the
** unsigned flag * that will make him output as uint if matched
*/

static inline const char
	*ptr_atoi(const char *str, int *ret, va_list ap)
{
	if (*str == '*')
	{
		*ret = va_arg(ap, unsigned);
		return (str + 1);
	}
	*ret = 0;
	while ('0' <= *str && *str <= '9')
		*ret = 10 * (*ret) + *str++ - '0';
	return (str);
}

/*
** get_len will consider the length flags h/hh/l/ll
** H = hh, L = ll
*/

static inline void
	get_len(char c, char *len_mod)
{
	if ((c == 'h' || c == 'l') && *len_mod == c)
		*len_mod = c - 32;
	else if (*len_mod == 0 || !(c == 'h' && *len_mod != 'H'))
		*len_mod = c;
}

/*
** get_fmt will look for padding existence
** H = hh, L = ll
*/

static inline const char
	*get_fmt(char const *str, t_modifier *mod, va_list ap)
{
	int			n;

	while (*str != '\0')
	{
		if (*str == '.')
			str = ptr_atoi(str + 1, &(mod->precision), ap) - 1;
		else if (('1' <= *str && *str <= '9') || *str == '*')
			str = ptr_atoi(str, &(mod->size), ap) - 1;
		else if ((n = is_in(*str, FLAGS_PADDING)) >= 0)
			mod->flag.t[n] = 1;
		else if (is_in(*str, FLAGS_WIDTH) >= 0)
			get_len(*str, &(mod->length));
		else if ((mod->conversion = *str))
			return (str + 1);
		str++;
	}
	return (str);
}

int
	ft_vasprintf(char **ret, char const *str, va_list ap)
{
	t_array		sstr;
	t_modifier	mod;
	char const	*ptr;

	sstr = NEW_ARRAY(char);
	fta_reserve(&sstr, ft_strlen(str));
	while (*str != '\0')
	{
		mod = NEW_MODIFIER;
		if (*str == '%' && (str = get_fmt(str + 1, &mod, ap)) && mod.conversion)
			convert(&mod, &sstr, ap);
		ptr = str;
		while (*ptr != '\0' && *ptr != '%')
			ptr++;
		if (ptr != str)
			fta_append(&sstr, (void *)str, ptr - str);
		str = ptr;
	}
	fta_append(&sstr, "\0", 1);
	fta_trim(&sstr);
	*ret = sstr.data;
	return (sstr.size - 1);
}
