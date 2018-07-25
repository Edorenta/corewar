/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 05:21:37 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/28 22:26:28 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_asm.h"

static void	ft_check_args(t_asm *comp, int i, int *total_size)
{
	int		ret;

	if (!(comp->r_str = ft_strsub(comp->line, i, ft_strlen(comp->line) - i)))
		ft_error(comp, "Malloc error (counting args)\n");
	ft_count_args(comp, comp->r_str, 3);
	i = 0;
	if ((ret = ft_get_type(comp->r_str[i], total_size)) == 1)
		i = ft_check_reg(comp, comp->r_str, i);
	else if (ret == 2)
		i = ft_check_dir(comp, comp->r_str, i);
	else
		i = ft_check_ind(comp, comp->r_str, i);
	i = ft_check_separator(comp, i, "Bad argument (ldi instruction)\n");
	if ((ret = ft_get_type(comp->r_str[i], total_size)) == 1)
		i = ft_check_reg(comp, comp->r_str, i);
	else if (ret == 2)
		i = ft_check_dir(comp, comp->r_str, i);
	else
		ft_error(comp, "Bad argument (ldi instruction)\n");
	i = ft_check_separator(comp, i, "Bad argument (ldi instruction)\n");
	ft_get_type(comp->r_str[i], total_size);
	i = ft_check_reg(comp, comp->r_str, i);
	if (comp->r_str[i])
		ft_error(comp, "Bad argument (ldi instruction)\n");
	(*total_size) = (*total_size) << 2;
}

void		ft_ldi(t_asm *comp, int i)
{
	int		total_size;
	int		label_index;

	total_size = 0;
	label_index = 2;
	ft_strdel(&comp->r_str);
	comp->data[comp->i++] = 10;
	i = ft_skip_whitespace(comp->line, i);
	ft_check_args(comp, i, &total_size);
	comp->data[comp->i++] = total_size;
	i = 0;
	i = ft_get_args(comp, i + ft_tsize(2, total_size >> 6, 1),
			ft_tsize(2, total_size >> 6, 0), label_index);
	label_index += ft_tsize(2, total_size >> 6, 0);
	i = ft_get_args(comp, i + ft_tsize(2, (total_size >> 4) & 0x3, 1),
			ft_tsize(2, (total_size >> 4) & 0x3, 0), label_index);
	label_index += ft_tsize(2, (total_size >> 4) & 0x3, 0);
	ft_get_args(comp, i + 1, 1, label_index);
}
