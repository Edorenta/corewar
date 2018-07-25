/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:15:12 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:25:26 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# ifndef STDINT_H
#  include <stdint.h>
# endif

# define BASE_UCASE     "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\0"
# define BASE_LCASE     "0123456789abcdefghijklmnopqrstuvwxyz\0"
# define STR_NULL       "(null)\n\0"

typedef struct	s_ftoa_base
{
	long long	whole;
	long long	fract;
	uint8_t		base;
	uint8_t		precision;
	int			dec;
	int			adjz;
	int			dig;
	char		neg;
}				t_ftoa_base;

typedef struct	s_ftoa_ns
{
	char		whole;
	long long	fract;
	uint8_t		precision;
	int			exp;
	int			dec;
	char		neg;
}				t_ftoa_ns;

int				ft_atoi(const char *str);
long			ft_atol(const char *str);
long long		ft_atoll(const char *str);
int				ft_atoi_base(const char *str, uint8_t base);
long			ft_atol_base(const char *str, uint8_t base);
long long		ft_atoll_base(const char *str, uint8_t base);
double			ft_atof_base(const char *str, uint8_t base);
double			ft_atof(const char *str);
char			*ft_itoa(int n);
char			*ft_ltoa(long n);
char			*ft_lltoa(long long n);
char			*ft_ftoa(double n, uint8_t precision);
char			*ft_ftoa_ns(double n);
char			*ft_itoa_base(int n, uint8_t base);
char			*ft_ltoa_base(long n, uint8_t base);
char			*ft_lltoa_base(long long n, uint8_t base);
char			*ft_ftoa_base(double n, uint8_t base, uint8_t precision);

#endif
