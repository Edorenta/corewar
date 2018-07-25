/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_mgmt.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:50:45 by pde-rent          #+#    #+#             */
/*   Updated: 2018/06/25 12:47:42 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_MGMT_H
# define STRING_MGMT_H

# ifndef STDDEF_H
#  include <stddef.h>
# endif

char	**ft_strsplit(const char *str, char c);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
int		ft_strchri(const char *str, int c);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strgetnp(char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strjoinfree(char *s1, char *s2, char **addr);
char	*ft_strljoin(char *s1, char *s2);
char	*ft_strmap(const char *str, char (*f)(char));
char	*ft_strmapi(const char *str, char (*f)(unsigned int, char));
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strndup(const char *str, size_t n);
char	*ft_strnew(size_t size);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strpbrk(const char *str, const char *lst);
char	*ft_strrchr(const char *str, int c);
char	*ft_strrev(char *str);
char	*ft_strrjoin(char *s1, char *s2);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strsub(const char *str, unsigned int start, size_t n);
char	*ft_strsubin(char *out, char **in, char c);
char	*ft_strtok(char *str, const char *sep);
char	*ft_strtrim(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strequ(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strnequ(const char *s1, const char *s2, size_t n);
int		is_in(char i, char const *str);
size_t	ft_strcspn(const char *str, const char *rej);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
void	ft_strclr(char *s);
void	ft_strdel(char **as);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

#endif
