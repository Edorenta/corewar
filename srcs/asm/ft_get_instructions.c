/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 01:45:16 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/29 02:25:17 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_asm.h"

static void	ft_inst_1(t_asm *comp, int i)
{
	if (!ft_strcmp(comp->r_str, "live"))
		ft_live(comp, i);
	else if (!ft_strcmp(comp->r_str, "zjmp"))
		ft_zjmp(comp, i);
	else if (!ft_strcmp(comp->r_str, "lfork"))
		ft_lfork(comp, i);
	else if (!ft_strcmp(comp->r_str, "or"))
		ft_or(comp, i);
	else if (!ft_strcmp(comp->r_str, "sub"))
		ft_sub(comp, i);
	else if (!ft_strcmp(comp->r_str, "and"))
		ft_and(comp, i);
	else if (!ft_strcmp(comp->r_str, "add"))
		ft_add(comp, i);
	else if (!ft_strcmp(comp->r_str, "xor"))
		ft_xor(comp, i);
	else
		ft_error(comp, "Unknown instruction\n");
}

static void	ft_inst_2(t_asm *comp, int i)
{
	if (!ft_strcmp(comp->r_str, "ld"))
		ft_ld(comp, i);
	else if (!ft_strcmp(comp->r_str, "st"))
		ft_st(comp, i);
	else if (!ft_strcmp(comp->r_str, "lldi"))
		ft_lldi(comp, i);
	else if (!ft_strcmp(comp->r_str, "sti"))
		ft_sti(comp, i);
	else if (!ft_strcmp(comp->r_str, "fork"))
		ft_fork(comp, i);
	else if (!ft_strcmp(comp->r_str, "ldi"))
		ft_ldi(comp, i);
	else if (!ft_strcmp(comp->r_str, "lld"))
		ft_lld(comp, i);
	else if (!ft_strcmp(comp->r_str, "aff"))
		ft_aff(comp, i);
	else
		ft_error(comp, "Unknown instruction\n");
}

static void	ft_find_instruction(t_asm *comp, int i)
{
	int		start;

	start = ft_skip_whitespace(comp->line, i);
	i = start;
	while (comp->line[i] && !ft_isspace(comp->line[i]))
		i++;
	if (!(comp->r_str = ft_strsub(comp->line, start, i - start)))
		ft_error(comp, "Malloc error (reading instruction)\n");
	if (!ft_strcmp(comp->r_str, "live") || !ft_strcmp(comp->r_str, "zjmp")
		|| !ft_strcmp(comp->r_str, "lfork") || !ft_strcmp(comp->r_str, "or")
		|| !ft_strcmp(comp->r_str, "sub") || !ft_strcmp(comp->r_str, "and")
		|| !ft_strcmp(comp->r_str, "add") || !ft_strcmp(comp->r_str, "xor"))
		ft_inst_1(comp, i);
	else if (!ft_strcmp(comp->r_str, "ld") || !ft_strcmp(comp->r_str, "st")
		|| !ft_strcmp(comp->r_str, "lldi") || !ft_strcmp(comp->r_str, "sti")
		|| !ft_strcmp(comp->r_str, "fork") || !ft_strcmp(comp->r_str, "ldi")
		|| !ft_strcmp(comp->r_str, "lld") || !ft_strcmp(comp->r_str, "aff"))
		ft_inst_2(comp, i);
	else
		ft_error(comp, "Unknown instruction\n");
	if (comp->r_str)
		ft_strdel(&comp->r_str);
}

void		ft_get_instructions(t_asm *comp)
{
	int		i;
	int		ret;

	ret = 1;
	while ((ret = get_next_line(comp->fd, &comp->line)) > 0)
	{
		ft_clean_line(comp);
		if (comp->line[0])
		{
			i = ft_get_label(comp, 0, comp->i);
			if (comp->line[i])
				ft_find_instruction(comp, i);
		}
		ft_strdel(&comp->line);
		if (comp->i - HEADER_LENGTH > CHAMP_MAX_SIZE)
			ft_error(comp, "Oh no, it's too big for me !\n");
	}
	if (comp->i - HEADER_LENGTH <= 0)
		ft_error(comp, "No code, no .cor !\n");
	if (ret == -1)
		ft_error(comp, "Error when reading file\n");
	i = comp->i;
	ft_place_size(comp);
	ft_place_labels(comp);
	comp->i = i;
}
