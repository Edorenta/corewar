/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:03:38 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/28 15:07:21 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	aff(t_vm *vm, t_proc *proc)
{
	int reg;

	if (!check_params(&proc->op))
		return ;
	reg = proc->op.ar[0];
	if (0x04 & vm->verbosity)
	{
		show_operations(proc);
		ft_printf("\n");
	}
}
