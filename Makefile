NAME	= cub3d
LIBFT	= libft

MLX = MLX42/libmlx42.a
FLAG_MLX = -framework Cocoa -framework OpenGL -framework IOKit -lglfw
INCLUDE = -I/Users/${USER}/.brew/Cellar/glfw/3.4/include/GLFW
LIB = -L/Users/${USER}/.brew/Cellar/glfw/3.4/lib
HEADERS = ./include/cub3d.h ./include/libft.h ./include/MLX42.h

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -O3 -ffast-math -MMD

DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

MOBJS	= ${SRCS:%.c=%.o}
SRCS = ./srcs/main.c ./srcs/utils/clean.c \
		./srcs/parsing/parse_main.c ./srcs/parsing/parse_utils.c \
		./srcs/parsing/copy_file.c ./srcs/utils/utils.c ./srcs/utils/print.c \
		./srcs/parsing/get_info.c ./srcs/parsing/colours.c ./srcs/parsing/map_check.c \
		./srcs/parsing/map_check1.c ./srcs/graphics/start.c  ./srcs/graphics/handlers.c \
		./srcs/graphics/movements.c ./srcs/graphics/raycasting.c ./srcs/graphics/render.c \
		./srcs/utils/raycast_utils.c ./srcs/utils/render_utils.c

DEPS = $(addsuffix .d, $(basename $(SRCS)))

all: $(NAME)

$(NAME): $(MOBJS) ${MLX} ${HEADERS}
	@make -s -C $(LIBFT)
	@$(CC) $(CFLAGS) $(FLAG_MLX) $(MOBJS) ${LIBFT}/libft.a $(MLX) $(LIB) -o $(NAME)
	@echo "\n$(RED) Created $(NAME) ✓ $(DEF_COLOR)\n"

%.o: %.c ./include/cub3d.h
	$(CC) $(CFLAGS) -I./include $(INCLUDE) -c $< -o $@
	@echo "$(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"

-include ${DEPS}

clean:
	@make clean -s -C $(LIBFT)
	@rm -f $(MOBJS)
	@rm -f ${DEPS}
	@echo "\n$(DARK_YELLOW) Removed all objects$(DEF_COLOR)\n"

fclean: clean
	@make fclean -s -C $(LIBFT)
	@rm -f $(NAME)
	@rm -f ${DEPS}
	@echo "\n$(DARK_YELLOW)Removed all objects and executable$(DEF_COLOR)\n"

re: fclean all