/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:34:27 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/29 09:39:00 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		first_free_nb_player(t_vm *vm)
{
	int i;

	i = 1;
	while (i <= MAX_PLAYERS)
	{
		if (!vm->player[i].active)
			return (i);
		i++;
	}
	return (0);
}

int		is_free_nb_player(t_vm *vm, int nb)
{
	if (!vm->nb_player)
		return (1);
	if (vm->player[nb].active)
		return (0);
	return (1);
}

int		search_nb_player(char **argv, int arg_num)
{
	if (arg_num - 2 > 0)
		if (ft_strstr(argv[arg_num - 2], "-n"))
			return (1);
	return (0);
}

int		get_nb_player(t_vm *vm, char **argv, int arg_num)
{
	int ret;

	ret = 0;
	if (search_nb_player(argv, arg_num))
	{
		ret = ft_atoi(argv[arg_num - 1]);
		if (ret > 0 && ret < 5 && is_free_nb_player(vm, ret))
			return (ret);
		else
			return (first_free_nb_player(vm));
	}
	else
		return (first_free_nb_player(vm));
	return (0);
}

int		search_players(t_vm *vm, int argc, char **argv)
{
	int		i;
	char	c[21];
	char	*tmp;

	i = 0;
	tmp = NULL;
	ft_bzero(c, 21);
	vm->nb_player = 0;
	while (++i < argc)
	{
		if ((tmp = ft_strstr(argv[i], ".cor")) && !tmp[4])
		{
			vm->nb_player++;
			if (vm->nb_player > MAX_PLAYERS)
				exit_error("Too many champs");
			new_player(vm, get_nb_player(vm, argv, i), argv[i]);
		}
	}
	if (vm->nb_player)
	{
		ft_sprintf(c, "%d, ", vm->nb_player);
		send_to_socket(vm, c, ft_strlen(c));
		return (0);
	}
	return (1);
}
