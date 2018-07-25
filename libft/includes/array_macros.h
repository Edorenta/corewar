/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_macros.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:50:45 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:20:32 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_MACROS_H
# define ARRAY_MACROS_H

# include "array_container.h"

# define NEW_ARRAY(T)			(t_array){NULL, 0, 0, sizeof(T)}
# define ARRAY_POPFRONT(A,N)	fta_popindex(A, 0, N)
# define ARRAY_INDEX_CHECK(A,I)	(0 <= (I) && (I) < (A)->size)
# define ARRAY_GET(A,I)			(ARRAY_START(A) + ARRAY_OFFSET(A,I))
# define ARRAY_GETS(A,I)		(ARRAY_INDEX_CHECK(A,I) ? ARRAY_GET(A,I) : NULL)
# define ARRAY_GETT(T,A,I)		((T*)ARRAY_GET(A,I))
# define ARRAY_GETTS(T,A,I)		((T*)ARRAY_GETS(A,I))
# define ARRAY_GETL(T,A,I)		(*ARRAY_GETT(T,A,I))
# define ARRAY_IFP(A,P)			((((void *)P) - (A)->data) / (A)->type_size)
# define ARRAY_ITERATOR(A)		(ARRAY_START(A) - ARRAY_STEP(A))
# define ARRAY_START(A)			((A)->data)
# define ARRAY_END(A)			((A)->data + (A)->size * (A)->type_size)
# define ARRAY_STEP(A)			((A)->type_size)
# define ARRAY_OFFSET(A,I)		((I) * ARRAY_STEP(A))
# define ARRAY_NEXT(A,IT)		((IT) += ARRAY_STEP(A))
# define ARRAY_HASNEXT(A,IT)	(ARRAY_NEXT(A,IT) < ARRAY_END(A))

#endif
