/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 06:11:16 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:29:24 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNICODE_H
# define UNICODE_H

# ifndef WCHAR_H
#  include <wchar.h>
# endif
# ifndef STDDEF_H
#  include <stddef.h>
# endif

size_t		ft_wcslen(const wchar_t *wstr);
size_t		ft_wstrconv(char *buff, const wchar_t *wstr);
size_t		ft_wstrnconv(char *buff, const wchar_t *wstr, size_t n);
size_t		ft_witoa(char *buff, wint_t w);

#endif
