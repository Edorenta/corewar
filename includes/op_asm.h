/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 06:58:11 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/07/03 08:14:08 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_ASM_H
# define OP_ASM_H

# include "libft.h"

# define REG_CODE	1
# define DIR_CODE	2
# define IND_CODE	3

# define MEM_SIZE			(4*1024)
# define CHAMP_MAX_SIZE		(MEM_SIZE / 6)

# define COMMENT_CHAR	'#'
# define LABEL_CHAR		':'
# define DIRECT_CHAR	'%'
# define SEPARATOR_CHAR	','

# define LABEL_CHARS	"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

# define REG_NUMBER	16

# define PROG_NAME_LENGTH	128
# define COMMENT_LENGTH		2048
# define HEADER_LENGTH		(PROG_NAME_LENGTH + COMMENT_LENGTH + 16)
# define COREWAR_EXEC_MAGIC	0x00ea83f3

typedef struct	s_idx
{
	int				idx;
	int				value;
	struct s_idx	*next;
}				t_idx;

typedef struct	s_lbl
{
	char			*name;
	int				confirmed;
	int				add;
	t_idx			*replace;
	struct s_lbl	*next;
}				t_lbl;

typedef struct	s_asm
{
	int		i;
	int		fd;
	char	*line;
	char	*r_str;
	char	*cor_file;
	char	*data;
	t_lbl	*label;
}				t_asm;

int				ft_check_dir(t_asm *comp, char *str, int i);
int				ft_check_ind(t_asm *comp, char *str, int i);
int				ft_check_reg(t_asm *comp, char *str, int i);
int				ft_check_separator(t_asm *comp, int i, char *error);
int				ft_get_args(t_asm *comp, int i, int size, int octet);
int				ft_get_label(t_asm *comp, int start, int pc);
int				ft_get_type(char c, int *total_size);
int				ft_skip_whitespace(char *str, int i);
int				ft_tsize(int dir_size, int type, int mode);
void			ft_add(t_asm *comp, int i);
void			ft_aff(t_asm *comp, int i);
void			ft_and(t_asm *comp, int i);
void			ft_clean_line(t_asm *comp);
void			ft_count_args(t_asm *comp, char *str, int nbr);
void			ft_create_file(t_asm *comp);
void			ft_display_labels(t_asm *comp);
void			ft_error(t_asm *comp, char *str);
void			ft_fork(t_asm *comp, int i);
void			ft_free_struct(t_asm *comp);
void			ft_get_header(t_asm *comp, int i, int ret);
void			ft_get_instructions(t_asm *comp);
void			ft_get_number(t_asm *comp, int start, int i);
void			ft_ld(t_asm *comp, int i);
void			ft_ldi(t_asm *comp, int i);
void			ft_lfork(t_asm *comp, int i);
void			ft_live(t_asm *comp, int i);
void			ft_lld(t_asm *comp, int i);
void			ft_lldi(t_asm *comp, int i);
void			ft_or(t_asm *comp, int i);
void			ft_place_labels(t_asm *comp);
void			ft_place_size(t_asm *comp);
void			ft_st(t_asm *comp, int i);
void			ft_sti(t_asm *comp, int i);
void			ft_sub(t_asm *comp, int i);
void			ft_xor(t_asm *comp, int i);
void			ft_zjmp(t_asm *comp, int i);
#endif
