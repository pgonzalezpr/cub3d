NAME = cub3d

SRCS = ./srcs/main.c ./srcs/clean.c ./srcs/utils/utils.c \
			
INCLUDE = ./include/cub3d.h ${LIBFT_DIR}/libft.h ${MINILIBX_DIR}/mlx.h

LIBFT_DIR = libft

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
MINILIBX_DIR = minilibx_macos
LIBRARIES = -lft -lmlx -lm -framework OpenGL -framework AppKit
endif
ifeq ($(UNAME), Linux)
MINILIBX_DIR = minilibx_linux
LIBRARIES = -lft -lmlx -lX11 -lXext
endif

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -MMD

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

%.o: %.c
	@${CC} ${CFLAGS} -I./include -c $< -o $@
	@echo "$(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"

OBJS = ${SRCS:.c=.o}
DEPS = $(addsuffix .d, $(basename $(SRCS)))

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT_DIR}/libft.a ${MINILIBX_DIR}/libmlx.a $(INCLUDE) Makefile
	@${CC} ${OBJS} -I./include -L${LIBFT_DIR} -L${MINILIBX_DIR} ${LIBRARIES} -o ${NAME}
	@echo "\n$(RED) Created $(NAME) ✓ $(DEF_COLOR)\n"

$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR)

${MINILIBX_DIR}/libmlx.a:
	@make -C $(MINILIBX_DIR)

-include ${DEPS}

clean:
	@${RM} ${OBJS}
	@${RM} ${DEPS}
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MINILIBX_DIR)
	@echo "\n$(DARK_YELLOW) Removed all objects$(DEF_COLOR)\n"

fclean: 
	@${RM} ${OBJS}
	@${RM} ${DEPS}
	@${RM} ${NAME}
	@make fclean -C $(LIBFT_DIR)
	@echo "\n$(DARK_YELLOW)Removed all objects and executable$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re

	
