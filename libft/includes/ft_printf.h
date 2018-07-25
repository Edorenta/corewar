/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:38:57 by pde-rent          #+#    #+#             */
/*   Updated: 2016/11/01 19:57:46 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "dependencies.h"

int		ft_printf(char const *format, ...);
int		ft_dprintf(int fd, char const *format, ...);
int		ft_asprintf(char **ret, char const *format, ...);
int		ft_sprintf(char *s, char const *format, ...);
int		ft_snprintf(char *s, size_t size, char const *format, ...);

int		ft_vprintf(char const *format, va_list ap);
int		ft_vdprintf(int fd, char const *format, va_list ap);
int		ft_vasprintf(char **ret, char const *s, va_list ap);
int		ft_vsprintf(char *s, char const *format, va_list ap);
int		ft_vsnprintf(char *s, size_t size, char const *format, va_list ap);

#endif
