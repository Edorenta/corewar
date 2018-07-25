/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:03:43 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/28 15:09:19 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	and(t_vm *vm, t_proc *proc)
{
	unsigned int arg1;
	unsigned int arg2;

	if (!check_params(&proc->op))
		return ;
	if (proc->op.ar_typ[0] == REG_CODE)
		arg1 = proc->reg[proc->op.ar[0]];
	else if (proc->op.ar_typ[0] == IND_CODE)
		arg1 = get_indirect(vm, &proc->op, 0);
	else
		arg1 = proc->op.ar[0];
	if (proc->op.ar_typ[1] == REG_CODE)
		arg2 = proc->reg[proc->op.ar[1]];
	else if (proc->op.ar_typ[1] == IND_CODE)
		arg2 = get_indirect(vm, &proc->op, 1);
	else
		arg2 = proc->op.ar[1];
	proc->reg[proc->op.ar[2]] = arg1 & arg2;
	proc->carry = (proc->reg[proc->op.ar[2]] == 0) ? 1 : 0;
	if (4 & vm->verbosity)
	{
		show_operations(proc);
		ft_printf("\n");
	}
}
