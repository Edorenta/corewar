/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:31:16 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/27 19:46:13 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_OP_H
# define MATHS_OP_H

# ifndef STDINT_H
#  include <stdint.h>
# endif

# define M_E        2.71828182845904523536
# define M_LOG2E    1.44269504088896340736
# define M_LOG10E   0.434294481903251827651
# define M_LN2      0.693147180559945309417
# define M_LN10     2.30258509299404568402
# define M_PI       3.14159265358979323846
# define M_PI_2     1.57079632679489661923
# define M_PI_4     0.785398163397448309616
# define M_1_PI     0.318309886183790671538
# define M_2_PI     0.636619772367581343076
# define M_2_SQRTPI 1.12837916709551257390
# define M_SQRT2    1.41421356237309504880
# define M_SQRT1_2  0.707106781186547524401

typedef union	u_ieee754
{
	uint64_t	u;
	double		f;

}				t_ieee754;

int				ft_getexp(double x);
double			ft_roundig(double x, uint8_t dig);
double			ft_roundec(double x, uint8_t dec);
double			ft_rint(double x);
float			ft_rintf(float x);
double			ft_copysign(double x, double y);
float			ft_copysignf(float x, float y);
int				ft_isnan(double x);
int				ft_isinf(double x);
int				ft_geti(double x);
long			ft_getl(double x);
long long		ft_getll(double x);
double			ft_getfrac(double x);
double			ft_getmantissa(double x);
double			ft_modf(double x, double *intptr);
int				ft_iabs(int nb);
long			ft_labs(long nb);
long long		ft_llabs(long long nb);
double			ft_dabs(double nb);
int				ft_ipow(int nb, uint8_t exp);
long			ft_lpow(long nb, uint8_t exp);
long long		ft_llpow(long long nb, uint8_t exp);
double			ft_dpow(double nb, uint8_t exp);
int				ft_ifact(int nb);
long			ft_lfact(long nb);
long long		ft_llfact(long long nb);
double			ft_dfact(double nb);
int				ft_idigits(int x, uint8_t b);
int				ft_ldigits(long x, uint8_t b);
int				ft_lldigits(long long x, uint8_t b);
int				ft_ddigits(double x, uint8_t b);
int				adj_zeros(double n);
int				ft_decimals(double x, uint8_t b);
double			ft_floor(double x);
double			ft_ceil(double x);
long			ft_fibo(int nb);
int				ft_gcd(int x, int y);
int				ft_rand(int min, int max);
int				ft_sqrt(int nb);
double			ft_cos(double x);
double			ft_sin(double x);
double			ft_tan(double x);

#endif
