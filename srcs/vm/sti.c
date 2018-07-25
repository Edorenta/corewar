/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:04:47 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/28 15:19:11 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		sti_verbose(t_proc *proc, int addr)
{
	show_operations(proc);
	ft_printf("\n       | -> store to %d + %d = %d (with pc and mod %d)\n",
	proc->op.ar[1], proc->op.ar[2], proc->op.ar[1] + proc->op.ar[2], addr);
}

static int		sti_set_value(t_vm *vm, t_proc *proc, int reg)
{
	int addr;

	addr = (proc->op.ar[1] + proc->op.ar[2]) % IDX_MOD;
	addr = proc->op.pos_opcode + addr;
	vm->ram[modulo(addr, MEM_SIZE)].mem = proc->reg[reg] >> 24;
	vm->ram[modulo(addr, MEM_SIZE)].num = proc->num;
	vm->ram[modulo(addr + 1, MEM_SIZE)].mem = proc->reg[reg] >> 16;
	vm->ram[modulo(addr + 1, MEM_SIZE)].num = proc->num;
	vm->ram[modulo(addr + 2, MEM_SIZE)].mem = proc->reg[reg] >> 8;
	vm->ram[modulo(addr + 2, MEM_SIZE)].num = proc->num;
	vm->ram[modulo(addr + 3, MEM_SIZE)].mem = proc->reg[reg];
	vm->ram[modulo(addr + 3, MEM_SIZE)].num = proc->num;
	return (addr);
}

void			sti(t_vm *vm, t_proc *proc)
{
	int addr;
	int reg;

	if (!check_params(&proc->op))
		return ;
	reg = proc->op.ar[0];
	if (proc->op.ar_typ[1] == REG_CODE)
	{
		proc->op.ar[1] = proc->reg[proc->op.ar[1]];
		proc->op.ar_typ[1] = DIR_CODE;
	}
	else if (proc->op.ar_typ[1] == IND_CODE)
		proc->op.ar[1] = get_indirect(vm, &proc->op, 1);
	if (proc->op.ar_typ[2] == REG_CODE)
	{
		proc->op.ar[2] = proc->reg[proc->op.ar[2]];
		proc->op.ar_typ[2] = DIR_CODE;
	}
	addr = sti_set_value(vm, proc, reg);
	if (0x4 & vm->verbosity)
		sti_verbose(proc, addr);
}
