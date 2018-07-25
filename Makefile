# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/07 19:21:52 by pde-rent          #+#    #+#              #
#    Updated: 2018/07/03 08:32:50 by fmadura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_NAME   	= asm
VM_NAME    	= corewar
ASM_SRC_PATH= srcs/asm/
VM_SRC_PATH	= srcs/vm/
ASM_OBJ_PATH= objs/asm/
VM_OBJ_PATH	= objs/vm/
FLAGS		= -Wall -Werror -Wextra #-g -fsanitize=address,undefined
LIB			= libft/libft.a
INC			= -Iincludes/ -Ilibft/includes
CC			= gcc $(FLAGS)
NAME_P		= $(shell echo $(ASM_NAME) | tr ' ' '\n' | sed "s/\.[acoh]$///g" | tr '\n' ' ' | sed "s/ $///g")

SRC_SUFFIX	= .c
OBJ_SUFFIX	= .o
#ASM_PREFIX	= 
#VM_PREFIX	=

ASM_SRC = \
	ft_parser \
	ft_get_header \
	ft_get_instructions \
	ft_get_label \
	ft_get_number \
	ft_place_labels_size \
	ft_args \
	ft_instruction_ft \
	ft_live \
	ft_ld \
	ft_st \
	ft_add \
	ft_sub \
	ft_and \
	ft_or \
	ft_xor \
	ft_zjmp \
	ft_ldi \
	ft_sti \
	ft_fork \
	ft_lld \
	ft_lldi \
	ft_lfork \
	ft_aff \
	ft_error \
	ft_create_file

VM_SRC = \
	corewar \
	check_arg \
	parse_player \
	player \
	parse_op \
	check_ocp \
	show \
	process \
	get_arg \
	core \
	op \
	tools \
	flib \
	action_proc \
	client \
	live \
	ld \
	st \
	add \
	sub \
	and \
	or \
	xor \
	zjmp \
	ldi \
	sti \
	lld \
	lldi \
	lfork \
	aff \
	fork

ASM_SRCS	= $(addprefix $(ASM_SRC_PATH), $(addsuffix $(SRC_SUFFIX),$(ASM_SRC)))
VM_SRCS		= $(addprefix $(VM_SRC_PATH),$(addsuffix $(SRC_SUFFIX),$(VM_SRC)))

ASM_OBJS	= $(addprefix $(OBJ_PATH), $(addsuffix $(OBJ_SUFFIX),$(ASM_SRC)))
VM_OBJS		= $(addprefix $(OBJ_PATH), $(addsuffix $(OBJ_SUFFIX),$(VM_SRC)))

#color
YELLOW		= "\\033[33m"
BLUE		= "\\033[34m"
RED			= "\\033[31m"
WHITE		= "\\033[0m"
CYAN		= "\\033[36m"
GREEN		= "\\033[32m"
BOLD		= "\\033[1m"
PINK		= "\\033[95m"

#command
EOLCLR		= "\\033[0K"
#unicode
CHECK		= "\\xE2\\x9C\\x94"
OK			= " $(CYAN)$(CHECK)$(WHITE)"

all : $(ASM_NAME) $(VM_NAME)
vm : $(VM_NAME)

$(ASM_NAME) : $(ASM_OBJS)
	@$(MAKE) -C libft/
	@printf "\r$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>\t$(YELLOW)$(BOLD)"\
	"Corewar ASM compiled\t"$(OK)'\n'
	@$(CC) $(INC) $(ASM_SRCS) -L libft/ -lft -o $@
	@printf "\r$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>\t$(GREEN)$(BOLD)"\
	"Build Successful\t"$(OK)'\n'

$(VM_NAME) : $(VM_OBJS)
	@$(MAKE) -C libft/
	@printf "\r$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>\t$(YELLOW)$(BOLD)"\
	"Corewar VM compiled\t"$(OK)'\n'
	@$(CC) $(INC) $(VM_SRCS) -L libft/ -lft -o $@
	@printf "\r$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>\t$(GREEN)$(BOLD)"\
	"Build Successful\t"$(OK)'\n'

$(ASM_OBJS) : | $(ASM_OBJ_PATH)
$(VM_OBJS) : | $(VM_OBJ_PATH)

$(ASM_OBJ_PATH) :
	@mkdir -p $(ASM_OBJ_PATH)

$(VM_OBJ_PATH) :
	@mkdir -p $(VM_OBJ_PATH)

(OBJ_PATH)%.o: $(ASM_SRC_PATH)%.c
	@printf "\r$(EOLCLR)[$(NAME_P)] compiling\t\t$(BOLD)$(YELLOW)$<$(WHITE)"
	@$(CC) $(INC) -o $@ -c $<
	@printf '\t'$(OK)

(OBJ_PATH)%.o: $(VM_SRC_PATH)%.c
	@printf "\r$(EOLCLR)[$(NAME_P)] compiling\t\t$(BOLD)$(YELLOW)$<$(WHITE)"
	@$(CC) $(INC) -o $@ -c $<
	@printf '\t'$(OK)

clean :
	@printf "[$(NAME_P)] removing\t\t$(PINK)all obj file$(WHITE)"
	@rm -rf ./objs
	@printf '\t\t'$(OK)'\n'
	@make clean -C ./libft
	
fclean : clean
	@printf "[$(NAME_P)] erasing\t\t$(PINK)$(ASM_NAME)$(WHITE)"
	@rm -f $(ASM_NAME)
	@rm -f $(VM_NAME)
	@printf '\t\t\t'$(OK)'\n'
	@make fclean -C ./libft

re : fclean all

norm :
	@norminette srcs/ include/

.PHONY: all clean fclean re norm
