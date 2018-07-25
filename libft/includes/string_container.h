/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_container.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:47:11 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:26:46 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_CONTAINER_H
# define STRING_CONTAINER_H

# include "array_container.h"
# include "array_macros.h"
# include "string_mgmt.h"

/*
** Vector<char> wraper using the Array Container
*/

typedef t_array			t_string;
typedef struct s_substr	t_substr;
struct					s_substr
{
	char		*str;
	size_t		len;
};

char					*ft_string(t_string *str);

#endif
