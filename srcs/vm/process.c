/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 23:27:01 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/29 09:59:23 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add_process(t_vm *vm, t_proc *proc)
{
	if (vm->proc)
		proc->next = vm->proc;
	vm->proc = proc;
}

t_proc	*create_process(t_vm *vm, int num)
{
	t_proc	*tmp;

	if (!(tmp = (t_proc*)ft_memalloc(sizeof(t_proc))))
	{
		free_all(vm);
		exit_error("Malloc Error");
	}
	tmp->id = set_proc_id(vm);
	tmp->num = num;
	tmp->pc = (MEM_SIZE / vm->nb_player) * ((num * (-1) - 1));
	tmp->last_pc = 0;
	ft_bzero(tmp->reg, sizeof(int) * (REG_NUMBER + 1));
	tmp->reg[1] = num;
	tmp->carry = 0;
	tmp->last_live = 0;
	tmp->active = 1;
	tmp->op.active = 0;
	tmp->next = NULL;
	return (tmp);
}

void	init_process(t_vm *vm)
{
	int i;

	i = 0;
	while (i <= MAX_PLAYERS)
	{
		if (vm->player[i].active)
			add_process(vm, create_process(vm, i * (-1)));
		i++;
	}
}

void	kill_proc(t_vm *vm)
{
	t_proc *tmp;
	t_proc *t;

	tmp = vm->proc;
	while (tmp)
	{
		if ((vm->cycle - tmp->last_live) >= vm->ctd && tmp->active)
			tmp->active = 0;
		if (tmp->next && !tmp->next->active)
		{
			t = tmp->next;
			tmp->next = tmp->next->next;
			free(t);
		}
		tmp = tmp->next;
	}
}

int		process_living(t_vm *vm)
{
	int		i;
	t_proc	*tmp;

	i = 0;
	tmp = vm->proc;
	if (vm->cycle < vm->next_ctd)
		return (1);
	kill_proc(vm);
	set_ctd(vm);
	vm->next_ctd = vm->cycle + vm->ctd;
	while (tmp)
	{
		if (tmp->active)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
