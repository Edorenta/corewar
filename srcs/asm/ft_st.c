/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 05:21:37 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/28 17:57:10 by fmadura          ###   ########.fr       */
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
	ft_get_type(comp->r_str[i], total_size);
	i = ft_check_reg(comp, comp->r_str, i);
	i = ft_check_separator(comp, i, "Bad argument (st instruction)\n");
	if ((ret = ft_get_type(comp->r_str[i], total_size)) == 1)
		i = ft_check_reg(comp, comp->r_str, i);
	else if (ret == 3)
		i = ft_check_ind(comp, comp->r_str, i);
	else
		ft_error(comp, "Bad argument (st instruction)\n");
	if (comp->r_str[i])
		ft_error(comp, "Bad argument (st instruction)\n");
	(*total_size) = (*total_size) << 4;
}

void		ft_st(t_asm *comp, int i)
{
	int		total_size;

	total_size = 0;
	ft_strdel(&comp->r_str);
	comp->data[comp->i++] = 3;
	i = ft_skip_whitespace(comp->line, i);
	ft_check_args(comp, i, &total_size);
	comp->data[comp->i++] = total_size;
	i = 0;
	i = ft_get_args(comp, i + 1, 1, 2);
	ft_get_args(comp, i + ft_tsize(4, (total_size >> 4) & 0x3, 1),
		ft_tsize(4, (total_size >> 4) & 0x3, 0), 3);
}
