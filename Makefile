# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 16:45:49 by maldavid          #+#    #+#              #
#    Updated: 2023/08/04 16:29:14 by maldavid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= ./cub3D

SRCS	=	srcs/core/main.c  \
			srcs/core/errors.c \
			srcs/core/input.c  \
			srcs/core/memory.c  \
			srcs/core/player.c  \
			srcs/core/application.c  \
			srcs/parser/parse.c  \
			srcs/renderer/init.c  \
			srcs/renderer/render.c  \
			srcs/utils/maths.c \
			srcs/utils/vec2_1.c \
			srcs/utils/vec2_2.c \
			srcs/utils/vec2_3.c \

OBJ_DIR	= objs
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -I third_party/libft -I includes -I third_party/mlx/includes
CLIBS	= third_party/libft/libft.a third_party/mlx/libmlx.so -lm `~/.xmake/packages/l/libsdl/2.28.1/afb2b93309a64808b8a666e3ffc1a405/bin/sdl2-config --cflags --libs` -lSDL2

BONUS		?= false
DEBUG		?= false
MODE		=  "release"
TOOLCHAIN	?= clang

ifeq ($(TOOLCHAIN), gcc)
	CC = gcc
endif

ifeq ($(BONUS), true)
	CFLAGS += -D BONUS
endif

ifeq ($(DEBUG), true)
	CFLAGS += -g -D DEBUG
	MODE = "debug"
endif

RM		= rm -rf

$(OBJ_DIR)/%.o: %.c
	@echo "\e[1;32m[compiling "$(MODE)" {"$(CC)"}...]\e[1;00m "$<
	@$(CC) $(CFLAGS) $(COPTS) -c $< -o $@

all:		libft mlx $(NAME)

libft:
	@make -C third_party/libft

mlx:
	@make -C third_party/mlx

$(NAME):	$(OBJ_DIR) $(OBJS)
	@echo "\e[1;32m[linking   "$(MODE)" {"$(CC)"}...]\e[1;00m "$@
	@$(CC) -o $(NAME) $(OBJS) $(CLIBS)
	@echo "\e[1;32m[build finished]\e[1;00m"

$(OBJ_DIR):
	@mkdir -p $(sort $(addprefix $(OBJ_DIR)/, $(dir $(SRCS))))

clean:
	@$(RM) $(OBJ_DIR)

fclean:		clean
	@$(RM) $(NAME)

re:			fclean all

norminette:
	@norminette | grep Error | wc -l

.PHONY:		all clean fclean re norminette libft mlx
