/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_macros.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 05:36:52 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:25:44 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_MACROS_H
# define PRIVATE_MACROS_H

# ifndef STDARG_H
#  include <stdarg.h>
# endif

/*
** Numbers manipulation tools dependencies
*/

# define _ARG_COUNT1(...) _ARG_COUNT2(A, ##__VA_ARGS__, _ARG_COUNT4)
# define _ARG_COUNT2(...) _ARG_COUNT3(__VA_ARGS__)
# define _ARG_COUNT3(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,n,...) n
# define _ARG_COUNT4 21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0

# define _TO_STR(M) #M
# define _CAT(A,B) A##B

# define _MIN1(A) (A)
# define _MIN2(A,B) ((A) < (B) ? (A) : (B))
# define _MIN3(A,B,C) (_MIN2(A, _MIN2(B, C)))
# define _MIN4(A,...) (_MIN2(A, _MIN3(__VA_ARGS__)))
# define _MIN5(A,...) (_MIN2(A, _MIN4(__VA_ARGS__)))
# define _MIN6(A,...) (_MIN2(A, _MIN5(__VA_ARGS__)))
# define _MIN7(A,...) (_MIN2(A, _MIN6(__VA_ARGS__)))
# define _MIN8(A,...) (_MIN2(A, _MIN7(__VA_ARGS__)))
# define _MIN9(A,...) (_MIN2(A, _MIN8(__VA_ARGS__)))

# define _MAX1(A) (A)
# define _MAX2(A,B) ((A) > (B) ? (A) : (B))
# define _MAX3(A,B,C) (_MAX2(A, _MAX2(B, C)))
# define _MAX4(A,...) (_MAX2(A, _MAX3(__VA_ARGS__)))
# define _MAX5(A,...) (_MAX2(A, _MAX4(__VA_ARGS__)))
# define _MAX6(A,...) (_MAX2(A, _MAX5(__VA_ARGS__)))
# define _MAX7(A,...) (_MAX2(A, _MAX6(__VA_ARGS__)))
# define _MAX8(A,...) (_MAX2(A, _MAX7(__VA_ARGS__)))
# define _MAX9(A,...) (_MAX2(A, _MAX8(__VA_ARGS__)))

/*
** Numbers manipulation tools
*/

# define ABS(V) ((V) < 0 ? -(V) : (V))

# define MIN(...) CAT(_MIN,ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
# define MAX(...) CAT(_MAX,ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)

/*
** Miscellaneous tricks
*/

# define ARG_COUNT(...) _ARG_COUNT1(__VA_ARGS__)

# define FD_PUT(F,A) write(F, A, ft_strlen(A))
# define FT_PUT(A) FD_PUT(1, A)

# define TO_STR(M) _TO_STR(M)
# define CAT(A,B) _CAT(A,B)

# define TWICE(A) (A),(A)
# define THRICE(A) (A),(A),(A)
# define PPP __VA_ARGS__

/*
** Asserts
*/

# ifdef DISABLE_ASSERT
#  define ASSERT(B) (B)
# else
#  define ASSERT(B) (B ? 1 : FD_PUT(2, __FILE__ " @" TO_STR(__LINE__) " : " #B))
# endif
# define ARRAY_SIZE(A) (sizeof(A) / sizeof(*A))

#endif
