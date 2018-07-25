/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_container.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:50:45 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:20:10 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_CONTAINER_H
# define ARRAY_CONTAINER_H

/*
** |		----------=====  Array<T>  =====----------
** The following functions allows one to manipulate a collection of objects,
** not bothering about malloc.
** It is inspired by the C++ "Vector<T>"
** -
** In C++ and Java, one would declare such an object with
** the template/generics syntax :
** |	Vector<SomeType> variable = new Vector<SomeType>();
** -
** Here in C,
** |	t_array	variable = NEW_ARRAY(t_some_type);
*/

# ifndef STDDEF_H
#  include <stddef.h>
# endif

# define ARRAY_INITIAL_SIZE		16
# define ARRAY_FACTOR			2

typedef struct	s_array
{
	void		*data;
	size_t		size;
	size_t		max;
	size_t		type_size;
}				t_array;

/*
** ----------===== Constructors =====----------
*/

t_array			fta_new(size_t type_size);
t_array			*fta_alloc(size_t type_size);

/*
** ----------===== Destructors  =====----------
*/

void			fta_clear(t_array *self);
void			fta_clearf(t_array *self, void (*del)(void *));
void			fta_release(t_array **ptr);

/*
** ------------===== Methods  =====------------
** ----- Insert -----
*/

int				fta_append(t_array *self, void const *data, size_t len);
int				fta_insert(t_array *self, void const *data,
				size_t len, size_t index);

/*
** ----- Remove -----
*/

void			fta_popback(t_array *self, size_t len);
void			fta_popbackf(t_array *self, size_t len, void (*del)(void *));
int				fta_popindex(t_array *self, size_t index, size_t len);
int				fta_popindexf(t_array *self, size_t index, size_t len,
				void (*del)(void *));
int				fta_overwrite(t_array *self, const t_array *other);
int				fta_replace(t_array *self, size_t index,
				size_t len, t_array *new);

/*
** ----- Other -----
*/

int				fta_resize(t_array *self, size_t new_size);
int				fta_reserve(t_array *self, size_t size);
int				fta_trim(t_array *self);
void			fta_iter(const t_array *self, void (*f)());
void			fta_iter1(const t_array *self, void (*f)(), void *a);
void			fta_iter2(const t_array *self, void (*f)(), void *a, void *b);
void			fta_iteri(const t_array *self, void (*f)());
void			fta_iteri1(const t_array *self, void (*f)(), void *a);
void			fta_iteri2(const t_array *self, void (*f)(), void *a, void *b);
char			*fta_string(t_array *self, char *(*f)(void *));
void			fta_swap(t_array *self, size_t before, size_t after);

#endif
