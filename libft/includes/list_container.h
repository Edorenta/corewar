/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_container.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:14:40 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:22:09 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_CONTAINER_H
# define LIST_CONTAINER_H

# ifndef STDDEF_H
#  include <stddef.h>
# endif

typedef struct		s_node
{
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_list
{
	t_node			root;
	size_t			type_size;
	size_t			size;
}					t_list;

/*
** ----------===== Constructors =====----------
*/

void				ftl_init(t_list *l, size_t type_size);
t_list				*ftl_alloc(size_t type_size);
int					ftl_cpy(t_list *dst, t_list const *src);

/*
** ----------===== Destructors  =====----------
*/

void				ftl_del();
void				ftl_free();

/*
** ------------===== Methods  =====------------
** ----- Insert -----
*/

int					ftl_push_front(t_list *l, t_node const *e);
int					ftl_push_back(t_list *l, t_node const *e);

/*
** ----- Remove -----
*/

void				ftl_pop_back(t_list *l);
void				ftl_pop_front(t_list *l);
void				ftl_pop_backf(t_list *l, void (*del)());
void				ftl_pop_elem(t_list *const l, t_node **const e);

#endif
