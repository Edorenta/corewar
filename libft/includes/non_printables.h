/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_print.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:15:12 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:22:44 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NON_PRINTABLES_H
# define NON_PRINTABLES_H

# define STRCATTMP2(x) #x
# define STRCATTMP1(x) STRCATTMP2(x)

# define NPP1	NULSOHSTXETXEOTENQACKBELBS\0TABLF\0VT\0FF\0CR\0SO\0SI\0
# define NPP2	DLEDC1DC2DC3DC4NAKSYNETBCANEM\0SUBESCFS\0GS\0RS\0US\0

# define NON_PRINT STRCATTMP1(NPP1) STRCATTMP1(NPP2)

#endif
