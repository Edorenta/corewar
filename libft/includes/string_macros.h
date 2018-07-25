/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_macros.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:50:45 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/25 12:34:57 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_MACROS_H
# define STRING_MACROS_H

# include "string_container.h"
# include "array_container.h"
# include "array_macros.h"

# define NEW_SUB(S)					(t_substr){S, S == NULL ? 0 : ft_strlen(S)}
# define NEW_STRING					NEW_ARRAY(char)
# define UPPER_CASE(C)				(C & ~(1 << 5))
# define LOWER_CASE(C)				(C | (1 << 5))
# define TOGGLE_CASE(C)				(C ^ (1 << 5))
# define IS_LOWER(C)				('a' <= C && C <= 'z')
# define IS_UPPER(C)				('A' <= C && C <= 'Z')
# define IS_ALPHA(C)				(IS_LOWER(C) || IS_UPPER(C))
# define IS_DIGIT(C)				('0' <= C && C <= '9')
# define IS_ALNUM(C)				(IS_ALPHA(C) || IS_DIGIT(C))
# define IS_BLANK(C)				(C == ' ' || C == '\t')
# define IS_SPACE(C)				(IS_BLANK(C) || C == '\v' || C == '\r')
# define FTSZ(STR)					(*(char *)ARRAY_END(STR) = '\0')
# define STR_JOIN_CS(S,CS,L)		(fta_append(S, CS, L))
# define STR_JOIN(STR,SUB)			fta_append(STR, (SUB)->str, (SUB)->len)
# define STR_INSERT(ST,SB,I)		fta_insert(ST, (void *)SB->str, SB->len, I)
# define STR_INSERT_CS(S,CS,L,I)	(fta_insert(S, (void *)CS, L, I))
# define STR_GET(STR,I)				ARRAY_GETT(char, STR, I)
# define STR_GETCHAR(STR,I)			(*ARRAY_GETT(char, STR, I))
# define STR_NULL_TERMINATE(STR)	(fta_reserve(STR, 1) || FTSZ(STR))
# define STR_CLEAN_REST(STR)		ft_bzero(ARRAY_END(S), (S)->max - (S)->size)

#endif
