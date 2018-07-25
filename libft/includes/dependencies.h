/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:38:16 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/25 11:33:56 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEPENDENCIES_H
# define DEPENDENCIES_H

# include <stdarg.h>
# include "libft.h"

# define FLAGS_FMT		"diuoxXfFeEgGaAOUcCsSpbrn\0"
# define FLAGS_NUM		"diuoxXfFeEgGaAOU\0"
# define FLAGS_WIDTH	"hljzL\0"
# define FLAGS_PADDING	"0+- #_\0"

typedef struct		s_modifier
{
	union
	{
		char		t[6];
		struct
		{
			char	zero;
			char	plus;
			char	minus;
			char	space;
			char	hash;
			char	uscore;
		}			pad;
	}				flag;
	char			conversion;
	char			length;
	int				base;
	int				size;
	int				precision;
}					t_modifier;

# define NEW_MODIFIER (t_modifier){{{0, 0, 0, 0, 0, 0}}, 0, 0, 10, -1, -1};

int					check_extrema(t_array *s, long double n, char mask);
char				*fta_ftoa_ns(double n, uint8_t precision, char mask);
int					fta_dtoa_ns(t_array *s, long double n, char mask,
							t_modifier *m);
int					fta_dtoa_g(t_array *s, long double n,
							char mask, t_modifier *m);
char				*fta_lltoa_base(long long n, uint8_t base, char mask);
char				*fta_ftoa_base(double n, uint8_t base,
							uint8_t precision, char mask);
int					fta_dtoa_base(t_array *s, long double n,
							char mask, t_modifier *m);
int					fta_itoa_base(t_array *s, intmax_t n, int b, char mask);
void				db_print_modifier(t_modifier *m);
void				convert(t_modifier *m, t_array *s, va_list ap);
int					fmt_int(t_modifier *m, t_array *s, va_list ap, int b);
int					fmt_uint(t_modifier *m, t_array *s, va_list ap, int b);
int					fmt_float(t_modifier *m, t_array *s, va_list ap, int b);
int					fmt_ns_float(t_modifier *m, t_array *s, va_list ap, int b);
int					fmt_g_float(t_modifier *m, t_array *s, va_list ap, int b);
int					fmt_di(t_modifier *m, t_array *s, va_list ap);
int					fmt_s(t_modifier *m, t_array *s, va_list ap);
int					fmt_ws(t_modifier *m, t_array *s, va_list ap);
int					fmt_c(t_modifier *m, t_array *s, va_list ap);
int					fmt_wc(t_modifier *m, t_array *s, va_list ap);
int					fmt_o(t_modifier *m, t_array *s, va_list ap);
int					fmt_u(t_modifier *m, t_array *s, va_list ap);
int					fmt_b(t_modifier *m, t_array *s, va_list ap);
int					fmt_p(t_modifier *m, t_array *s, va_list ap);
int					fmt_n(t_modifier *m, t_array *s, va_list ap);
int					fmt_r(t_modifier *m, t_array *s, va_list ap);
int					fmt_f(t_modifier *m, t_array *s, va_list ap);
int					fmt_cf(t_modifier *m, t_array *s, va_list ap);
int					fmt_a(t_modifier *m, t_array *s, va_list ap);
int					fmt_ca(t_modifier *m, t_array *s, va_list ap);
int					fmt_g(t_modifier *m, t_array *s, va_list ap);
int					fmt_cg(t_modifier *m, t_array *s, va_list ap);
int					fmt_x(t_modifier *m, t_array *s, va_list ap);
int					fmt_cx(t_modifier *m, t_array *s, va_list ap);
int					fmt_e(t_modifier *m, t_array *s, va_list ap);
int					fmt_ce(t_modifier *m, t_array *s, va_list ap);

#endif
