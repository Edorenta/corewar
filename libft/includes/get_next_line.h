/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:15:12 by pde-rent          #+#    #+#             */
/*   Updated: 2018/07/03 08:26:24 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef UNISTD_H
#  include <unistd.h>
# endif
# ifndef STDLIB_H
#  include <stdlib.h>
# endif
# include "string_mgmt.h"
# include "memory_mgmt.h"
# ifndef LIMITS_H
#  include <limits.h>
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 5000
# endif

# define BUFF_SIZE 42
# ifndef IS
#  define IS(x) if (!x) return (0);
# endif

int		get_next_line(const int fd, char **line);

#endif
