/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_labels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06:08:30 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/28 17:56:52 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_asm.h"

void	ft_place_size(t_asm *comp)
{
	if (!(comp->r_str = ft_itoa(comp->i - HEADER_LENGTH)))
		ft_error(comp, "Malloc error (placing champion size)\n");
	comp->i = PROG_NAME_LENGTH + 8;
	ft_get_number(comp, 0, 4);
	ft_strdel(&comp->r_str);
}

void	ft_place_labels(t_asm *comp)
{
	t_lbl	*tmp1;
	t_idx	*tmp2;

	tmp1 = comp->label;
	while (tmp1)
	{
		if (!tmp1->confirmed)
			ft_error(comp, "A label is not defined\n");
		tmp2 = tmp1->replace;
		while (tmp2)
		{
			if (!(comp->r_str = ft_itoa(tmp1->add - tmp2->value)))
				ft_error(comp, "Malloc error (placing labels)\n");
			comp->i = tmp2->idx % 100000000;
			ft_get_number(comp, 0, tmp2->idx / 100000000);
			ft_strdel(&comp->r_str);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
