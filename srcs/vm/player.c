/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:33:51 by jjourne           #+#    #+#             */
/*   Updated: 2018/07/01 21:24:46 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	new_player(t_vm *vm, int nb, char *str)
{
	vm->player[nb].active = 1;
	vm->player[nb].file_name = str;
}

char	*get_data(t_player *player, char *buff)
{
	int		fd;
	int		ret;

	fd = 0;
	ret = 0;
	fd = open(player->file_name, O_RDONLY);
	if (fd < 0)
		exit_error("File error");
	player->read_ret = read(fd, buff, sizeof(t_header) + CHAMP_MAX_SIZE);
	if (player->read_ret < (int)sizeof(t_header))
		exit_error("File size error");
	return (buff);
}

int		get_prog_size(char *data)
{
	int ret;

	data += MAGIC_NB;
	data += PROG_NAME;
	ret = 0x0;
	ret = ret | (unsigned char)*data;
	ret = ret << 8;
	ret = ret | (unsigned char)data[1];
	ret = ret << 8;
	ret = ret | (unsigned char)data[2];
	ret = ret << 8;
	ret = ret | (unsigned char)data[3];
	if (ret > CHAMP_MAX_SIZE)
		exit_error("Champ is too big");
	return (ret);
}

void	write_player(t_vm *vm, int nb, int num)
{
	int		i;
	char	*data;
	int		prog_size;
	char	buff[sizeof(t_header) + CHAMP_MAX_SIZE];

	i = (MEM_SIZE / vm->nb_player) * num;
	data = get_data(&vm->player[nb], buff);
	ft_memcpy(vm->player[nb].name, data + MAGIC_NB, PROG_NAME);
	ft_strlen(vm->player[nb].name) ? 0 : exit_error("Empty name");
	ft_memcpy(vm->player[nb].comments, data + MAGIC_NB + PROG_NAME + PROG_SIZE,
		PROG_COMS);
	ft_strlen(vm->player[nb].comments) ? 0 : exit_error("Empty comments");
	prog_size = get_prog_size(data);
	if (!prog_size || vm->player[nb].read_ret != prog_size + sizeof(t_header))
		exit_error("Bad prog_size");
	ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		nb, prog_size, vm->player[nb].name, vm->player[nb].comments);
	prog_size += i;
	while (i < prog_size)
	{
		vm->ram[i % MEM_SIZE].mem = (unsigned char)*(data + SRC_BEGIN);
		vm->ram[i % MEM_SIZE].num = (num + 1) * -1;
		data++;
		i++;
	}
}

void	create_players(t_vm *vm)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	ft_printf("Introducing contestants...\n");
	send_to_socket(vm, "$<set>[", 7);
	while (i <= MAX_PLAYERS)
	{
		if (vm->player[i].active)
		{
			write_player(vm, i, j);
			j++;
			send_player(vm, j);
		}
		i++;
	}
	send_to_socket(vm, "]", 1);
	init_process(vm);
}
