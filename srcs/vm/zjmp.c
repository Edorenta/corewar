/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:05:05 by jjourne           #+#    #+#             */
/*   Updated: 2018/07/03 08:12:15 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_vm *vm, t_proc *proc)
{
	if (proc->carry)
	{
		proc->pc = modulo(proc->op.pos_opcode + (proc->op.ar[0] % IDX_MOD),
		MEM_SIZE);
		proc->last_pc = proc->pc;
	}
	if (0x4 & vm->verbosity)
	{
		show_operations(proc);
		if (proc->carry)
			ft_printf(" OK");
		else
			ft_printf(" FAILED");
		ft_printf("\n");
	}
}
