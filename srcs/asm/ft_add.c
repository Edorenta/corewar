/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 08:07:05 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/03 08:07:13 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_asm.h"

static void	ft_check_args(t_asm *comp, int i, int *total_size)
{
	if (!(comp->r_str = ft_strsub(comp->line, i, ft_strlen(comp->line) - i)))
		ft_error(comp, "Malloc error (counting args)\n");
	ft_count_args(comp, comp->r_str, 3);
	*total_size = 0x54;
	i = ft_check_reg(comp, comp->r_str, 0);
	i = ft_check_separator(comp, i, "Bad argument (add instruction)\n");
	i = ft_check_reg(comp, comp->r_str, i);
	i = ft_check_separator(comp, i, "Bad argument (add instruction)\n");
	i = ft_check_reg(comp, comp->r_str, i);
	if (comp->r_str[i])
		ft_error(comp, "Bad argument (add instruction)\n");
}

void		ft_add(t_asm *comp, int i)
{
	int		total_size;

	ft_strdel(&comp->r_str);
	comp->data[comp->i++] = 4;
	i = ft_skip_whitespace(comp->line, i);
	ft_check_args(comp, i, &total_size);
	comp->data[comp->i++] = total_size;
	i = ft_get_args(comp, 1, 1, 2);
	i = ft_get_args(comp, i + 1, 1, 3);
	ft_get_args(comp, i + 1, 1, 4);
}
