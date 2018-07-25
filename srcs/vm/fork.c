/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:03:48 by jjourne           #+#    #+#             */
/*   Updated: 2018/07/02 19:52:47 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		registre_cpy(t_proc *proc, t_proc *new)
{
	int i;

	i = 0;
	while (i <= REG_NUMBER)
	{
		new->reg[i] = proc->reg[i];
		i++;
	}
}

static void		clone_proc(t_proc *proc, t_proc *new)
{
	registre_cpy(proc, new);
	new->carry = proc->carry;
	new->last_live = proc->last_live;
	new->num = proc->num;
}

void			op_fork(t_vm *vm, t_proc *proc)
{
	t_proc	*new;

	new = create_process(vm, proc->num);
	init_op(&new->op);
	new->pc = modulo(proc->op.pos_opcode + (proc->op.ar[0] % IDX_MOD),
	MEM_SIZE);
	new->last_pc = new->pc;
	clone_proc(proc, new);
	add_process(vm, new);
	if (0x4 & vm->verbosity)
	{
		show_operations(proc);
		ft_printf(" (%d)\n", new->pc);
	}
}
