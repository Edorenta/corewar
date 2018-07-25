/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_classification.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:18:25 by pde-rent          #+#    #+#             */
/*   Updated: 2017/12/09 11:19:14 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_CLASS_H
# define CHAR_CLASS_H

int		ft_skip_whitespace(char *str, int i);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isblank(int c);
int		ft_iscntrl(int c);
int		ft_isdigit(int c);
int		ft_isgraph(int c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_ispunct(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isxdigit(int c);
int		ft_isoperator(int c);

#endif
