/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:04:54 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/28 15:19:33 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sub(t_vm *vm, t_proc *proc)
{
	int	n;

	if (!check_params(&proc->op))
		return ;
	n = proc->reg[proc->op.ar[0]] - proc->reg[proc->op.ar[1]];
	proc->reg[proc->op.ar[2]] = n;
	proc->carry = (n == 0) ? 1 : 0;
	if (0x4 & vm->verbosity)
	{
		show_operations(proc);
		ft_printf("\n");
	}
}
