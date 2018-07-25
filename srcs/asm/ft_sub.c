/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 05:21:37 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/28 17:57:35 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_asm.h"

static void	ft_check_args(t_asm *comp, int i, int *total_size)
{
	if (!(comp->r_str = ft_strsub(comp->line, i, ft_strlen(comp->line) - i)))
		ft_error(comp, "Malloc error (counting args)\n");
	ft_count_args(comp, comp->r_str, 3);
	i = 0;
	*total_size = 0x54;
	i = ft_check_reg(comp, comp->r_str, i);
	i = ft_check_separator(comp, i, "Bad argument (sub instruction)\n");
	i = ft_check_reg(comp, comp->r_str, i);
	i = ft_check_separator(comp, i, "Bad argument (sub instruction)\n");
	i = ft_check_reg(comp, comp->r_str, i);
	if (comp->r_str[i])
		ft_error(comp, "Bad argument (sub instruction)\n");
}

void		ft_sub(t_asm *comp, int i)
{
	int		total_size;

	total_size = 0;
	ft_strdel(&comp->r_str);
	comp->data[comp->i++] = 5;
	i = ft_skip_whitespace(comp->line, i);
	ft_check_args(comp, i, &total_size);
	comp->data[comp->i++] = total_size;
	i = 0;
	i = ft_get_args(comp, i + 1, 1, 2);
	i = ft_get_args(comp, i + 1, 1, 3);
	ft_get_args(comp, i + 1, 1, 4);
}
