/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream_mgmt.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:37:02 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:26:18 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAM_MGMT_H
# define STREAM_MGMT_H

# ifndef FCNTL_H
#  include <fcntl.h>
# endif
# ifndef UIO_H
#  include <sys/uio.h>
# endif
# ifndef UNISTD_H
#  include <unistd.h>
# endif
# ifndef STDLIB_H
#  include <stdlib.h>
# endif
# include "string_macros.h"

typedef struct s_is		t_is;
typedef struct s_fis	t_fis;
typedef struct s_sis	t_sis;

/*
** Input Stream
** -
** Expected behavior :
** > one calls refresh
** > if it returns 1, buff points to a string of len buff_len
** -
** /-------------------\
** |    InputStream    |
** |-------------------|
** | char*        buff |
** | uint     buff_len |
** | uint       buff_i |
** |-------------------|
** | bool      refresh |
** \-------------------/
*/

struct					s_is
{
	const char	*buff;
	int			(*refresh)(t_is *self);
	size_t		buff_i;
	size_t		buff_len;
};

/*
** File Input Stream
** -
** /----------------------------------------\
** | FileInputStream implements InputStream |
** |----------------------------------------|
** |----------------------------------------|
** \----------------------------------------/
*/

struct					s_fis
{
	t_is		super;
	int			fd;
	int			opened;
};

/*
** String Input Stream
*/

struct					s_sis
{
	t_is		super;
	t_string	*ptr;
};

/*
** Constructors
*/

# define NEW_IS(F) (t_is){NULL,F,0,0}
# define NEW__IS(B,S,F) (t_is){B,F,0,S}

# define NEW_SIS(S) (t_sis){NEW_IS(&sis_refresh), S}

/*
** trying to fit this in 80 chars :(
** -
** # define NEW__SIS(S) (t_sis){NEW__IS(ARRAY_GETT(const char, S, 0), \
** (S)->size, &sis_refresh), S}
*/

# define NEW_FIS() (t_fis){NEW_IS(&fis_refresh), -1, 0}
# define NEW__FIS(S) (t_fis){NEW_IS(&fis_refresh), open(S, O_RDONLY), 1}

/*
** Tools
*/

# define FIS_OPEN(A,S) ((A)->fd = open(S, O_RDONLY))
# define FIS_CLOSE(A) (close((A)->fd))

# define IS_REFRESH(I) ((I)->buff_i >= (I)->buff_len ? _IS_REFRESH(I) : 0)
# define _IS_REFRESH(IS) (((t_is *)(IS))->refresh((t_is *)IS))

# define IS_CURRENT(IS) (((t_is *)IS)->buff + ((t_is *)IS)->buff_i)
# define IS_CURRENTC(IS) (*IS_CURRENT(IS))

/*
** |	----------===== private: =====----------
*/

/*
** Size of a buffer
*/

# define FIS_BUFF_SIZE 512

/*
** StringInputStream::refresh
** -
** returns 1 if the string has been read entirely.
*/

int						sis_refresh(t_is *self);

/*
** FileInputStream::refresh
*/

int						fis_refresh(t_is *self);

/*
** FileInputStream::_getBuffer
** -
** the buffer may be modified internaly.
** However the buffer is constant publicly.
*/

# define FIS_BUFFER(SIS) ((char *)(((t_is *)SIS)->buff))

#endif
