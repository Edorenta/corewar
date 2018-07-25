CC =				gcc
EXEC =				corewar
SRC_DIR =			./
OBJ_DIR =			./obj/
HEADER_DIR =		./../../includes/
HEADER_LIBFT_DIR = 	./../../libft/includes/
LIBFT_DIR = 		./../../libft/
LIBFT =			$(LIBFT_DIR)libft.a
CFLAGS =			-Wall -Werror -Wextra
DEBUG_FLAGS =		-fsanitize=address -g
INCLUDES =			-I../../includes/ -I../../libft/includes/
CFILES = 			corewar check_arg parse_player \
					player parse_op check_ocp \
					show process get_arg \
					core op tools \
					flib action_proc client \
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

SRC =				$(CFILES:%=$(SRC_DIR)%.c)
OBJ =				$(CFILES:%=$(OBJ_DIR)%.o)

all: $(EXEC)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(EXEC): $(LIBFT) $(OBJ)
	echo $(HEADER_LIBFT_DIR)
	$(CC) $(INCLUDES) $(SRC) $(LIBFT) -o $@ $(CFLAGS) #$(DEBUG_FLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -I$(HEADER_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo clean $@ Done !

fclean:	clean
	rm -f $(EXEC)
	@make -C $(LIBFT_DIR) fclean
	@echo fclean $@ Done !

dbg:
	echo $(HEADER_LIBFT_DIR)
re:		fclean all

.PHONY: clean fclean re
.SUFFIXES:
