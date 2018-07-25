/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:04:40 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/28 15:17:46 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		st_set_value(t_vm *vm, t_proc *proc)
{
	unsigned int addr;

	addr = (proc->op.pos_opcode + (proc->op.ar[1] % IDX_MOD));
	addr = modulo(addr, MEM_SIZE);
	vm->ram[addr].mem = proc->reg[proc->op.ar[0]] >> 24;
	vm->ram[addr].num = proc->num;
	addr = modulo(addr + 1, MEM_SIZE);
	vm->ram[addr].mem = proc->reg[proc->op.ar[0]] >> 16;
	vm->ram[addr].num = proc->num;
	addr = modulo(addr + 1, MEM_SIZE);
	vm->ram[addr].mem = proc->reg[proc->op.ar[0]] >> 8;
	vm->ram[addr].num = proc->num;
	addr = modulo(addr + 1, MEM_SIZE);
	vm->ram[addr].mem = proc->reg[proc->op.ar[0]];
	vm->ram[addr].num = proc->num;
}

void			st(t_vm *vm, t_proc *proc)
{
	if (!check_params(&proc->op))
		return ;
	if (proc->op.ar_typ[1] == REG_CODE)
	{
		if (proc->op.ar[1] >= 1 && proc->op.ar[1] <= 16)
			proc->reg[proc->op.ar[1]] = proc->reg[proc->op.ar[0]];
	}
	else
		st_set_value(vm, proc);
	if (0x4 & vm->verbosity)
	{
		show_operations(proc);
		ft_printf("\n");
	}
}
