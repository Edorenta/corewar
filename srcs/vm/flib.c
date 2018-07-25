/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flib.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:40:25 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/28 20:22:59 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_str_isdigit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int		ft_strargv(int argc, char **argv, char *str)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strstr(argv[i], str))
			return (i);
		i++;
	}
	return (0);
}

void	reset_live(t_vm *vm)
{
	int				i;

	i = 1;
	while (i <= vm->nb_player)
	{
		vm->player[i].life_signal = 0;
		++i;
	}
}
