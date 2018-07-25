#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/07 17:38:00 by pde-rent          #+#    #+#              #
#    Updated: 2018/06/25 11:32:54 by fmadura          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME    	= libft.a
SRCS_PATH	= srcs/
OBJS_PATH	= objs/
I_PATH		= -I includes
FLAGS		= -Wall -Wextra -g $(I_PATH) #-Wpedantic
CC			= clang $(FLAGS)
SRCS_SUBDIRS= $(shell find $(SRCS_PATH) -type d)
SRCS_FILES	= $(shell find $(SRCS_PATH)/* -type f -name "*.c"\
				 -exec basename {} \;)
OBJS_FILES	= $(SRCS_FILES:.c=.o)
SRCS		= $(shell find $(SRCS_PATH) -type f -name "*.c")
OBJS		= $(addprefix $(OBJS_PATH),$(OBJS_FILES))
NAME_P		= $(shell echo $(NAME) | tr ' ' '\n' |\
				sed "s/\.[acoh]$///g" | tr '\n' ' ' | sed "s/ $///g")

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

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>>\t$(YELLOW)$(BOLD)"\
	"all binaries compiled\t"$(OK)'\n'
	@printf "[$(NAME_P)] building library $@$(WHITE)"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf '\t\t'$(OK)'\n'

$(OBJS) : | $(OBJS_PATH)

$(OBJS_PATH) :
	@mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)*/%.c | $(TRACKER)
	@printf "$(EOLCLR)[$(NAME_P)] compiling\t$(BOLD)$(YELLOW)$<$(WHITE)\r"
	@$(CC) -c $< -o $@

%.c:
	@printf "$(RED)Missing file : $@$(WHITE)\n"

$(TRACKER): $(SRCS)
	@touch $(TRACKER)
	@mkdir -p $(OBJS_PATH)

clean:
	@printf "[$(NAME_P)] cleaning\t$(PINK)all obj file$(WHITE)"
	@rm -rf $(OBJS_PATH)
	@rm -f $(TRACKER)
	@printf '\t\t'$(OK)'\n'

fclean: clean
	@printf "[$(NAME_P)] erasing\t\t$(PINK)$(NAME)$(WHITE)"
	@rm -f $(NAME)
	@printf '\t\t\t'$(OK)'\n'

re: fclean
	@$(MAKE) all

norm:
	@echo $(RED)
	@norminette $(SRCS) $(I_PATH) | grep -v Norme -B1 || true
	@echo $(END)

.PHONY: all clean fclean re norm
