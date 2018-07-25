/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:04:10 by jjourne           #+#    #+#             */
/*   Updated: 2018/07/02 23:13:23 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_vm *vm, t_proc *proc)
{
	int		num;
	char	buf[50000];

	vm->lives_in_cycle++;
	proc->last_live = vm->cycle + 1;
	num = proc->op.ar[0] * -1;
	if (4 & vm->verbosity)
	{
		show_operations(proc);
		ft_printf("\n");
	}
	if (num >= 1 && num <= vm->nb_player)
	{
		vm->player[num].life_signal++;
		vm->player[num].last_live = vm->cycle;
		ft_printf("Player %d (%s) is said to be alive\n",
			num, vm->player[num].name);
		send_to_socket(vm, "$<liv>[", 7);
		ft_sprintf(buf, "\"%d\", \"%d\"", num, proc->id);
		send_to_socket(vm, buf, ft_strlen(buf));
		send_to_socket(vm, "]", 1);
	}
}
