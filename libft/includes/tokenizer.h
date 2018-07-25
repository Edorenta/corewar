/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 05:43:19 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:28:27 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "stream_mgmt.h"
# ifndef STDINT_H
#  include <stdint.h>
# endif

typedef struct s_tokenizer	t_tokenizer;
typedef struct s_token		t_token;

struct						s_token
{
	uint8_t		tag;
	t_substr	data;
};

struct						s_tokenizer
{
	t_is *const	in;
	t_token		current;
	int			eof;
};

/*
** Fields shouldnt be modified by the user.
*/

# define NEW_TOKENIZER(IS) (t_tokenizer){IS, NEW_TOKEN, 0}
# define NEW_TOKEN (t_token){0, {NULL, 0}}

#endif
