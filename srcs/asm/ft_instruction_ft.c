/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_ft.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 08:25:21 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/03 08:25:22 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_asm.h"

int			ft_check_separator(t_asm *comp, int i, char *error)
{
	if (comp->r_str[i++] != SEPARATOR_CHAR)
		ft_error(comp, error);
	i = ft_skip_whitespace(comp->r_str, i);
	return (i);
}

static int	ft_skip_separator(char *str, int i)
{
	while (str[i] && (ft_isspace(str[i]) || str[i] == SEPARATOR_CHAR))
		i++;
	return (i);
}

int			ft_get_args(t_asm *comp, int i, int size, int octet)
{
	char	*tmp;

	if (comp->r_str[i] == LABEL_CHAR)
	{
		tmp = comp->r_str;
		if (!(comp->r_str = ft_strsub(comp->r_str, i,
			ft_strlen(comp->r_str) - i)))
			ft_error(comp, "Malloc error (getting label)\n");
		free(tmp);
		ft_get_label(comp, 1, (comp->i - octet) + (size * 100000000));
		i = -1;
		while (++i < size)
			comp->data[comp->i++] = 0;
	}
	else
		ft_get_number(comp, i, size);
	while (comp->r_str[i] && !ft_isspace(comp->r_str[i])
			&& !(comp->r_str[i] == SEPARATOR_CHAR))
		i++;
	return (ft_skip_separator(comp->r_str, i));
}

int			ft_get_type(char c, int *total_size)
{
	*total_size = *total_size << 2;
	if (c == 'r')
	{
		(*total_size) += REG_CODE;
		return (REG_CODE);
	}
	else if (c == DIRECT_CHAR)
	{
		(*total_size) += DIR_CODE;
		return (DIR_CODE);
	}
	(*total_size) += IND_CODE;
	return (IND_CODE);
}

int			ft_tsize(int dir_size, int type, int mode)
{
	if (mode == 1)
	{
		if (type == IND_CODE)
			return (0);
		return (1);
	}
	if (type == REG_CODE)
		return (1);
	else if (type == DIR_CODE)
		return (dir_size);
	return (2);
}
