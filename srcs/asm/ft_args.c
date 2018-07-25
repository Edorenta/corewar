/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:40:59 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/28 17:47:37 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_asm.h"

int		ft_check_reg(t_asm *comp, char *str, int i)
{
	int		start;
	int		nbr;
	char	*tmp;

	if (str[i] != 'r')
		ft_error(comp, "Bad parameter (not a register)\n");
	i++;
	start = i;
	while (ft_isdigit(str[i]))
		i++;
	if (!(tmp = ft_strsub(str, start, i - start)))
		ft_error(comp, "Malloc error (checking register)\n");
	nbr = ft_atoi(tmp);
	free(tmp);
	if (nbr < 1 || nbr > REG_NUMBER)
		ft_error(comp, "Bad reg number\n");
	i = ft_skip_whitespace(str, i);
	return (i);
}

int		ft_check_ind(t_asm *comp, char *str, int i)
{
	if (str[i] == DIRECT_CHAR || str[i] == 'r')
		ft_error(comp, "Bad parameter (not an indirect)\n");
	if (str[i] == LABEL_CHAR)
	{
		i++;
		while (ft_strchr(LABEL_CHARS, str[i]))
			i++;
	}
	else
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (ft_isdigit(str[i]))
			i++;
	}
	i = ft_skip_whitespace(str, i);
	return (i);
}

int		ft_check_dir(t_asm *comp, char *str, int i)
{
	if (str[i] != DIRECT_CHAR)
		ft_error(comp, "Bad parameter (not a direct)\n");
	i++;
	if (str[i] == LABEL_CHAR)
	{
		i++;
		while (ft_strchr(LABEL_CHARS, str[i]))
			i++;
	}
	else
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (ft_isdigit(str[i]))
			i++;
	}
	i = ft_skip_whitespace(str, i);
	return (i);
}

void	ft_count_args(t_asm *comp, char *str, int nbr)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] && str[i] != SEPARATOR_CHAR && !ft_isspace(str[i]))
			i++;
		i = ft_skip_whitespace(str, i);
		if (str[i] == SEPARATOR_CHAR)
			i = ft_skip_whitespace(str, i + 1);
		nb++;
	}
	if (nb != nbr)
		ft_error(comp, "Bad number of parameters\n");
}
