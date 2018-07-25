/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:22:52 by pde-rent          #+#    #+#             */
/*   Updated: 2017/05/17 09:58:50 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ftl_add(t_node *prev, t_node *node, t_node *next)
{
	prev->next = node;
	node->prev = prev;
	node->next = next;
	next->prev = node;
}

int			ftl_push_front(t_list *l, t_node const *e)
{
	t_node *node;

	if (!(node = (t_node *)ft_memdup(e, l->type_size)))
		return (1);
	ftl_add((t_node *)l, node, l->root.next);
	l->size++;
	return (0);
}

int			ftl_push_back(t_list *l, t_node const *e)
{
	t_node *node;

	if (!(node = (t_node *)ft_memdup((void const *)e, l->type_size)))
		return (1);
	ftl_add(l->root.prev, node, (t_node *)l);
	l->size++;
	return (0);
}
