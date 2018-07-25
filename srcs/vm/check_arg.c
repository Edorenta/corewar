/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:29:46 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/29 06:03:49 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		search_nb_dump(int argc, char **argv)
{
	int ret;
	int nb;

	ret = 0;
	nb = 0;
	if ((ret = ft_strargv(argc, argv, "-d")))
	{
		if (ft_strlen(argv[ret]) > 2)
			exit_error("Bad argument\n");
		if ((ret + 1) < argc && ft_str_isdigit(argv[ret + 1]))
			return (ft_atoi(argv[ret + 1]));
		else
			exit_error("Dump bad number\n");
	}
	return (-1);
}

int		search_vizu(int argc, char **argv)
{
	int ret;

	ret = 0;
	if ((ret = ft_strargv(argc, argv, "-g")))
		return (1);
	return (0);
}

int		srch_verbose(int argc, char **argv)
{
	int ret;
	int nb;

	ret = 0;
	nb = 0;
	if ((ret = ft_strargv(argc, argv, "-v")))
	{
		if ((ret + 1) < argc && ft_str_isdigit(argv[ret + 1]))
			return (ft_atoi(argv[ret + 1]));
		else
			exit_error("Verbosity bad number\n");
	}
	return (0);
}

int		check_arg(t_vm *vm, int argc, char **argv)
{
	if (argc == 1)
		usage();
	vm->dump = search_nb_dump(argc, argv);
	if (!vm->dump)
		vm->dump++;
	vm->vizu = search_vizu(argc, argv);
	if (vm->vizu)
		vm->sock = init_socket();
	vm->verbosity = srch_verbose(argc, argv);
	if (search_players(vm, argc, argv))
		return (1);
	return (0);
}
