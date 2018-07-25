/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 07:15:12 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/28 21:12:11 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_asm.h"
#include <fcntl.h>
#include <unistd.h>

void		ft_create_file(t_asm *comp)
{
	comp->fd = open(comp->cor_file, O_CREAT | O_TRUNC | O_WRONLY, 00644);
	if (comp->fd == -1)
		ft_error(comp, "Error when creating .cor\n");
	write(comp->fd, comp->data, comp->i);
	ft_printf("File %s created\n", comp->cor_file);
	close(comp->fd);
}
