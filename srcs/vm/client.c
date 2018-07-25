/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 22:06:34 by pde-rent          #+#    #+#             */
/*   Updated: 2018/07/02 18:15:25 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	send_exe(t_vm *vm, t_proc *proc)
{
	char	buf[50000];

	ft_bzero(buf, 50000);
	send_to_socket(vm, "$<exe>[", 7);
	ft_sprintf(buf, "\"%d\",\"%d\",\"%d\"",
	ft_iabs(proc->num), proc->pc, proc->id);
	send_to_socket(vm, buf, ft_strlen(buf));
	send_to_socket(vm, "]", 1);
	send_mem(vm);
	send_num_player(vm);
}

void	send_player(t_vm *vm, int nb)
{
	char	c[129];

	if (vm->vizu)
	{
		ft_bzero(c, 129);
		(nb == vm->nb_player || vm->nb_player == 1)
		? ft_sprintf(c, "\"%s\"", vm->player[nb].name)
		: ft_sprintf(c, "\"%s\",", vm->player[nb].name);
		send_to_socket(vm, c, ft_strlen(c));
	}
}

void	send_to_socket(t_vm *vm, char *payload, size_t size)
{
	int ret;

	if (vm->vizu)
		ret = send(vm->sock, payload, size, 0);
}

int		init_socket(void)
{
	int					sock;
	struct sockaddr_in	serv_addr;

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		ft_printf("Socket creation error\n");
		exit(EXIT_FAILURE);
	}
	ft_memset(&serv_addr, '0', sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
	{
		ft_printf("Invalid address/ Address not supported\n");
		exit(EXIT_FAILURE);
	}
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		ft_printf("Connection Failed\n");
		exit(EXIT_FAILURE);
	}
	return (sock);
}
