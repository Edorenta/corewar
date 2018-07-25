/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:30:58 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/25 12:35:39 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			ret;
	static char	*str[OPEN_MAX + 1];

	if (!(line) || fd < 0 || fd > OPEN_MAX)
		return (-1);
	if (fd > -1 && str[fd] && ft_strchri(str[fd], '\n') != -1)
	{
		str[fd] = ft_strsubin(str[fd], line, '\n');
		return (1);
	}
	if ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str[fd] = ((!str[fd]) ? ft_strdup(buff) : ft_strljoin(str[fd], buff));
		return (get_next_line(fd, line));
	}
	if (ret == 0 && str[fd] && str[fd][0])
	{
		*line = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
		return (1);
	}
	return (ret > 0 ? 1 : ret);
}
