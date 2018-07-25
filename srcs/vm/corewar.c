/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:12:22 by jjourne           #+#    #+#             */
/*   Updated: 2018/07/02 03:55:15 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_reg(int nb)
{
	if (nb < 1 || nb > REG_NUMBER)
		return (0);
	return (1);
}

int		check_params(t_op *op)
{
	int i;

	i = 0;
	while (i < g_op_tab[op->code - 1].nb_arg)
	{
		if (op->ar_typ[i] == REG_CODE)
		{
			if (!check_reg(op->ar[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

void	get_winner(t_vm *vm)
{
	int i;
	int best;

	i = 1;
	best = 0;
	vm->player[best].last_live = 0;
	while (i <= MAX_PLAYERS)
	{
		if (vm->player[i].active)
		{
			if (vm->player[i].last_live > vm->player[best].last_live)
				best = i;
		}
		i++;
	}
	if (!best)
		++best;
	vm->winner = best;
}

void	init_vm(t_vm *vm)
{
	vm->nb_player = 0;
	vm->lives_in_cycle = 0;
	vm->ctd = CYCLE_TO_DIE;
	vm->cycle = 0;
	vm->proc = NULL;
	vm->last_one = NULL;
	vm->ctd_check = 0;
	vm->next_ctd = CYCLE_TO_DIE;
	vm->dump = -1;
	vm->winner = 0;
	ft_bzero(vm->player, sizeof(t_player) * 5);
	ft_bzero(vm->ram, sizeof(t_mem) * MEM_SIZE);
}

int		main(int argc, char *argv[])
{
	t_vm		vm;
	char		buf[255];

	ft_bzero(&vm, sizeof(t_vm));
	ft_bzero(buf, 255);
	init_vm(&vm);
	if (check_arg(&vm, argc, argv))
		exit_error("Error: arguments invalide");
	create_players(&vm);
	run(&vm);
	get_winner(&vm);
	ft_printf("Contestant %d, \"%s\", has won !\n", vm.winner,
		vm.player[vm.winner].name);
	send_to_socket(&vm, "$<end>", 6);
	ft_sprintf(buf, "Contestant %d, \"%s\", has won !\n", vm.winner,
		vm.player[vm.winner].name);
	send_to_socket(&vm, buf, ft_strlen(buf));
	free_all(&vm);
	return (0);
}
