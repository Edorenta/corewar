/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 23:26:12 by jjourne           #+#    #+#             */
/*   Updated: 2018/07/03 06:22:47 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		is_opcode(char data)
{
	if (data > 0 && data < 17)
		return (1);
	return (0);
}

void	dump(t_vm *vm)
{
	if (vm->cycle == vm->dump)
	{
		show_mem(vm);
		free_all(vm);
		exit(EXIT_SUCCESS);
	}
}

void	exec_proc(t_vm *vm, t_proc *proc)
{
	vm->ram[proc->pc % MEM_SIZE].pc = 0;
	if (!proc->op.active)
	{
		if (is_opcode(vm->ram[proc->pc % MEM_SIZE].mem))
			create_op(proc, vm->ram[proc->pc % MEM_SIZE].mem);
		else
			proc->pc = (proc->pc + 1) % MEM_SIZE;
	}
	else
	{
		proc->op.loadtime--;
		if (proc->op.loadtime <= 0)
		{
			if (fill_cur_op(vm, proc))
				g_op_tab[proc->op.code - 1].func(vm, proc);
			if (proc->op.code != 9 || (proc->op.code == 9 && !proc->carry))
				proc->pc += move_pc(proc);
			proc->pc = modulo(proc->pc, MEM_SIZE);
			send_exe(vm, proc);
			delete_op(proc);
		}
	}
	vm->ram[proc->pc % MEM_SIZE].pc = proc->num;
}

void	run(t_vm *vm)
{
	t_proc	*proc;
	char	buf[50000];

	ft_bzero(buf, 50000);
	while (process_living(vm))
	{
		if (!((vm->cycle + 1) % vm->ctd))
			reset_live(vm);
		if (2 & vm->verbosity)
			ft_printf("It is now cycle %d\n", vm->cycle + 1);
		proc = vm->proc;
		send_to_socket(vm, "$<cyc>[", 7);
		ft_sprintf(buf, "\"%d\",", vm->cycle);
		send_to_socket(vm, buf, ft_strlen(buf));
		ft_sprintf(buf, "\"%d\"", vm->ctd);
		send_to_socket(vm, buf, ft_strlen(buf));
		send_to_socket(vm, "]", 1);
		list_proc(vm, proc);
		vm->cycle++;
		if (vm->dump != -1)
			dump(vm);
	}
	if (vm->last_one)
		ft_printf("Last_one => %s\n", vm->last_one->file_name);
}
