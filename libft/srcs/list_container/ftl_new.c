/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:51:19 by pde-rent          #+#    #+#             */
/*   Updated: 2017/12/14 10:51:50 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_container.h"
#include <stdlib.h>

void	ftl_init(t_list *l, size_t type_size)
{
	*l = (t_list){{(t_node *)l, (t_node *)l}, type_size, 0};
}

t_list	*ftl_alloc(size_t type_size)
{
	t_list *ret;

	if (!(ret = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	*ret = (t_list){{(t_node *)ret, (t_node *)ret}, type_size, 0};
	return (ret);
}

int		ftl_cpy(t_list *dst, t_list const *src)
{
	t_node const *ptr;

	ptr = (t_node const *)src;
	*dst = (t_list){{(t_node *)dst, (t_node *)dst}, src->type_size, 0};
	while ((ptr = ptr->next) != (t_node const *)src)
		if (!(((((((((((((ftl_push_back(dst, ptr)))))))))))))))
			return (1);
	return (0);
}
