/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outsubin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:28:46 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/25 12:32:00 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubin(char *out, char **in, char c)
{
	char	*tmp;

	*in = ft_strsub(out, 0, ft_strchri(out, c));
	tmp = ft_strsub(out, ft_strchri(out, c) + 1, ft_strlen(out));
	free(out);
	out = ft_strdup(tmp);
	free(tmp);
	return (out);
}
