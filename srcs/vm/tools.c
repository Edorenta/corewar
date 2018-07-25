/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:34:56 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/30 20:41:00 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_all(t_vm *vm)
{
	t_proc *tmp;
	t_proc *tmp2;

	tmp = vm->proc;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	vm->proc = NULL;
}

void	exit_error(const char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

int		modulo(int a, int b)
{
	if (a % b >= 0)
		return (a % b);
	else
		return ((a % b) + b);
}

void	usage(void)
{
	ft_printf("Usage: ./corewar [-d N | -ncurses ] <[-n N] ");
	ft_printf("champion1.cor> <...>\n");
	ft_printf("  -d N\t\t: Dumps memory after N cycles then exits\n");
	ft_printf("  -v N\t\t: Verbosity levels, can be added together to enable ");
	ft_printf("several\n");
	ft_printf("\t\t\t- 2 : Show cycles\n");
	ft_printf("\t\t\t- 4 : Show operations (Params are NOT litteral ...)\n");
	ft_printf("  -g\t: Graphics output mode\n");
	ft_printf("  -n N\t\t: Champion number (position at initalisation of ");
	ft_printf("memory)\n");
	exit(EXIT_FAILURE);
}

int		count_octet(int octet, t_optab *ref)
{
	if (octet == 1)
		return (1);
	else if (octet == 2)
		return ((ref->direct_size) ? 2 : 4);
	else if (octet == 3)
		return (IND_SIZE);
	return (0);
}
