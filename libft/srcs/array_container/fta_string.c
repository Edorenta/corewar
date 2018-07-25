/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:09:32 by pde-rent          #+#    #+#             */
/*   Updated: 2017/02/27 19:15:34 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_macros.h"
#include "string_mgmt.h"

#define TMP_STRING_APPEND(A,S) fta_append(A, S, ft_strlen(S))

/*
** Array::string
** -
** toString
** description
** -
** _f_ converts an element to a string.
** -
** Returns a string representing the given array.
*/

char	*fta_string(t_array *self, char *(*f)(void *))
{
	t_array		ret[1];
	void		*iterator;
	char		*tmp;

	*ret = NEW_ARRAY(char);
	fta_reserve(self, self->size * 3 + 10);
	TMP_STRING_APPEND(ret, "[|");
	iterator = ARRAY_START(self);
	tmp = f(iterator);
	TMP_STRING_APPEND(ret, tmp);
	while (ARRAY_HASNEXT(self, iterator))
	{
		TMP_STRING_APPEND(ret, ", ");
		tmp = f(iterator);
		TMP_STRING_APPEND(ret, tmp);
	}
	fta_append(ret, "|]", 3);
	return ((char *)ret->data);
}

#undef TMP_STRING_APPEND
