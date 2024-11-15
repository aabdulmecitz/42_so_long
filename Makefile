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

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

REMOVE 			= rm -f

SRCS_DIR		= ./src/

SRCS 			= $(addprefix $(SRCS_DIR),\
				ft_check_command_line_args.c \
				ft_error_msg.c  ft_free_map.c \
				ft_init_map.c \
				ft_intit_game.c \
				so_long.c)

# Default target to build the program
all:			${NAME} ${LIBFT} 

# Rule to create the executable
${NAME}: 		
				${CC} ${STANDARD_FLAGS} ${SRCS} ${LIBFT} -L./lib/minilibx-linux ${MLX} ${MINILIBX_FLAGS} -o ${NAME}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

# Rule to build libft
${LIBFT}:
				@echo
				make bonus -C lib/libft

# Clean rule to remove object files
clean:
				make clean -C lib/libft
				@echo

# Full clean rule
fclean:
				${REMOVE} ${NAME} ${NAME_BONUS}
				@echo "${NAME}: ${RED}${NAME} and ${NAME_BONUS} were deleted${RESET}"
				@echo

# Rebuild rule
re:				fclean all

# Run the program with valgrind
run:			${NAME}
				${VALGRIND} ./${NAME} assets/maps/valid/map4.ber

.PHONY:			all clean fclean re rebonus valgrind run run_bonus makefile
