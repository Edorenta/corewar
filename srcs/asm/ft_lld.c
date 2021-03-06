/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 05:21:37 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/28 20:50:50 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_asm.h"

static void	ft_check_args(t_asm *comp, int i, int *total_size)
{
	int		ret;

	if (!(comp->r_str = ft_strsub(comp->line, i, ft_strlen(comp->line) - i)))
		ft_error(comp, "Malloc error (counting args)\n");
	ft_count_args(comp, comp->r_str, 2);
	i = 0;
	if ((ret = ft_get_type(comp->r_str[i], total_size)) == 2)
		i = ft_check_dir(comp, comp->r_str, i);
	else if (ret == 3)
		i = ft_check_ind(comp, comp->r_str, i);
	else
		ft_error(comp, "Bad argument (lld instruction)\n");
	i = ft_check_separator(comp, i, "Bad argument (lld instruction)\n");
	ft_get_type(comp->r_str[i], total_size);
	i = ft_check_reg(comp, comp->r_str, i);
	if (comp->r_str[i])
		ft_error(comp, "Bad argument (lld instruction)\n");
	(*total_size) = (*total_size) << 4;
}

void		ft_lld(t_asm *comp, int i)
{
	int		total_size;
	int		label_index;

	label_index = 2;
	total_size = 0;
	ft_strdel(&comp->r_str);
	comp->data[comp->i++] = 13;
	i = ft_skip_whitespace(comp->line, i);
	ft_check_args(comp, i, &total_size);
	comp->data[comp->i++] = total_size;
	i = 0;
	i = ft_get_args(comp, i + ft_tsize(4, total_size >> 6, 1),
		ft_tsize(4, total_size >> 6, 0), label_index);
	label_index += ft_tsize(4, total_size >> 6, 0);
	ft_get_args(comp, i + 1, 1, label_index);
}
