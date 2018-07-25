#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/07 17:38:00 by pde-rent          #+#    #+#              #
#    Updated: 2018/03/14 18:46:06 by pde-rent         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME    	= libft.a
SRCS_PATH	= .
OBJS_PATH	= objs/
I_PATH		= ../../include/
FLAGS		= -Wall -Werror -Wextra -g -I$(I_PATH) #-Wpedantic
CC			= gcc $(FLAGS)
SRC_SUBDIRS	= $(shell find $(SRCS_PATH) -type d)
SRCS		= $(shell find $(SRCS_PATH) -type f -name "*.c")
OBJS		= $(SRCS:.c=.o)
NAME_P		= $(shell echo $(NAME) | tr ' ' '\n' |\
				sed "s/\.[acoh]$///g" | tr '\n' ' ' | sed "s/ $///g")
OBJS_TRACKER= .objs_exist
MAKEFLAGS	+=-j

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

# ONLY FOR LONG TERM IMPROVEMENT
all: $(NAME)

$(NAME): $(OBJS)

$(OBJS): $(SRCS) | $(OBJS_TRACKER)
	@$(CC) -o $(OBJS_PATH)$@ -c $<

%.c:
	@printf "[$(NAME_P)] $(RED)missing file : $@$(WHITE)\n"

$(OBJS_TRACKER):
	@mkdir -p $(OBJS_PATH)
	@touch $(OBJS_TRACKER)

clean:
	@rm -rf $(OBJS_PATH)
	@rm -f $(OBJS_TRACKER)

fclean: clean
	@rm -f $(OBJS_TRACKER)

re: fclean all

norm :
	@norminette $(SRCS_PATH) $(I_PATH)

.PHONY: all clean fclean re norm
