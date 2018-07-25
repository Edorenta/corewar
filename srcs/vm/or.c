/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:04:36 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/28 15:16:12 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	or(t_vm *vm, t_proc *proc)
{
	if (!check_params(&proc->op))
		return ;
	if (proc->op.ar_typ[0] == REG_CODE)
	{
		proc->op.ar[0] = proc->reg[proc->op.ar[0]];
		proc->op.ar_typ[0] = DIR_CODE;
	}
	else if (proc->op.ar_typ[0] == IND_CODE)
		proc->op.ar[0] = get_indirect(vm, &proc->op, 0);
	if (proc->op.ar_typ[1] == REG_CODE)
	{
		proc->op.ar[1] = proc->reg[proc->op.ar[1]];
		proc->op.ar_typ[1] = DIR_CODE;
	}
	else if (proc->op.ar_typ[1] == IND_CODE)
		proc->op.ar[1] = get_indirect(vm, &proc->op, 1);
	proc->reg[proc->op.ar[2]] = proc->op.ar[0] | proc->op.ar[1];
	proc->carry = (proc->reg[proc->op.ar[2]] == 0) ? 1 : 0;
	if (0x4 & vm->verbosity)
	{
		show_operations(proc);
		ft_printf("\n");
	}
}
