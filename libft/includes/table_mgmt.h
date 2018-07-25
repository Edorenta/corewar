/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_mgmt.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:50:45 by pde-rent          #+#    #+#             */
/*   Updated: 2017/03/21 06:15:23 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_MGMT_H
# define TABLE_MGMT_H

int		ft_arraymin(int *tab, int n);
int		ft_arraymax(int *tab, int n);
int		ft_arraymean(int *tab, int n);
int		ft_arraymedian(int *tab, int n);
void	ft_arrayrev(int *tab, int left, int right);
void	ft_arrayprint(int *tab, int n, char sep);
void	ft_arraysort(int *tab, int first, int last, int dir);
int		ft_tabmin(int **tab, int x, int y);
int		ft_tabmax(int **tab, int x, int y);
int		ft_tabmean(int **tab, int x, int y);
int		ft_tabmedian(int **tab, int x, int y);

#endif
