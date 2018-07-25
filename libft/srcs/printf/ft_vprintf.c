/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:16:43 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/04 20:52:58 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vprintf(char const *fmt, va_list ap)
{
	return (ft_vdprintf(1, fmt, ap));
}

int		ft_vdprintf(int fd, char const *fmt, va_list ap)
{
	char		*str;
	int			ret;

	ret = ft_vasprintf(&str, fmt, ap);
	write(fd, str, ret);
	free(str);
	return (ret);
}

int		ft_vsprintf(char *s, char const *fmt, va_list ap)
{
	char		*str;
	int			ret;

	ret = ft_vasprintf(&str, fmt, ap);
	ft_strcpy(s, str);
	free(str);
	return (ret);
}

int		ft_vsnprintf(char *s, size_t size, char const *fmt, va_list ap)
{
	char		*str;
	int			ret;

	ret = ft_vasprintf(&str, fmt, ap);
	ft_strncpy(s, str, size);
	free(str);
	return (ret);
}
