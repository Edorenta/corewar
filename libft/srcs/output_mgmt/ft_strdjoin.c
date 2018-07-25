/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 17:10:23 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/25 12:28:15 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdjoin(char *s1, char *s2)
{
	char *new;

	new = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		new = ft_strjoin(s1, s2);
		if (s1)
			free(s1);
		if (s2)
			free(s2);
	}
	return (new);
}
