/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 05:21:37 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/28 17:55:09 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_asm.h"

static void	ft_check_args(t_asm *comp, int i)
{
	if (!(comp->r_str = ft_strsub(comp->line, i, ft_strlen(comp->line) - i)))
		ft_error(comp, "Malloc error (counting args)\n");
	ft_count_args(comp, comp->r_str, 1);
	i = ft_check_dir(comp, comp->r_str, 0);
	if (comp->r_str[i])
		ft_error(comp, "Bad argument (live instruction)\n");
}

void		ft_live(t_asm *comp, int i)
{
	ft_strdel(&comp->r_str);
	comp->data[comp->i++] = 1;
	i = ft_skip_whitespace(comp->line, i);
	ft_check_args(comp, i);
	ft_get_args(comp, 1, 4, 1);
}
