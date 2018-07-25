/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 02:55:15 by pde-rent          #+#    #+#             */
/*   Updated: 2017/03/13 17:27:59 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_mgmt.h"
#include "string_macros.h"

/*
** String::toChar*
** -
** Handy function to use a String as a char*
*/

char	*ft_string(t_string *str)
{
	STR_NULL_TERMINATE(str);
	return ((char *)str->data);
}
