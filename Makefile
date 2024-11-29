NAME			= so_long
NAME_BONUS		= so_long_bonus

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

LIBFT 			= lib/libft/libft.a

CC 				= cc

STANDARD_FLAGS 	= -Wall -Werror -Wextra
MINILIBX_FLAGS	= -lXext -lX11
MLX = ./lib/minilibx-linux/libmlx.a

VALGRIND		= @valgrind --leak-check=full

REMOVE 			= rm -f

SRCS_DIR		= ./src/

SRCS 			= $(addprefix $(SRCS_DIR),\
				ft_check_command_line_args.c \
				ft_msg.c ft_init_game.c\
				ft_check_map.c ft_init_map.c\
				so_long.c ft_mem_free.c ft_render_frame.c\
				ft_flood_fill.c ft_handle_buttons.c)

all:			${NAME} ${LIBFT} 

${NAME}: 		
				${CC} ${SRCS} ${LIBFT} -L./lib/minilibx-linux ${MLX} ${MINILIBX_FLAGS} -g3 -o ${NAME}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

${LIBFT}:
				@echo
				make bonus -C lib/libft

clean:
				make clean -C lib/libft
				@echo

fclean:
				${REMOVE} ${NAME} ${NAME_BONUS}
				@echo "${NAME}: ${RED}${NAME} and ${NAME_BONUS} were deleted${RESET}"
				@echo
push:
	git add .
	git commit -m "commit"
	git push

re:				fclean all

compile_libs:
	@make -sC lib/libft
	@make -sC lib/minilibx-linux
	@make clean -sC lib/libft

update:
	git submodule update --init --recursive --remote

run:			re
				./${NAME} assets/maps/valid/map2.ber 

valgrind: re
	$(VALGRIND) ./${NAME} assets/maps/valid/map2.ber 


.PHONY:			all clean fclean re rebonus valgrind run run_bonus makefile
