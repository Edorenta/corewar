/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 22:11:16 by pde-rent          #+#    #+#             */
/*   Updated: 2017/03/15 22:22:40 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_container.h"
#include <stdlib.h>

void	ftl_del(t_list *l)
{
	t_node		*tmp;

	tmp = l->root.next;
	while ((tmp = tmp->next) != l->root.next)
		free(tmp->prev);
	l->size = 0;
}

void	ftl_free(t_list **l)
{
	ftl_del(*l);
	*l = NULL;
}
