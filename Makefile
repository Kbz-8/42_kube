# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maldavid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 16:45:49 by maldavid          #+#    #+#              #
#    Updated: 2023/07/31 16:51:39 by maldavid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= ./cub3D

SRCS	=	srcs/core/main.c \

OBJ_DIR	= objs
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -I third_party/libft -I includes
CLIBS	= third_party/libft/libft.a -lm

DEBUG		?= false
MODE		=  "release"
TOOLCHAIN	?= clang

ifeq ($(TOOLCHAIN), gcc)
	CC = gcc
endif

ifeq ($(DEBUG), true)
	CFLAGS += -g -D DEBUG
	MODE = "debug"
endif

RM		= rm -rf

$(OBJ_DIR)/%.o: %.c
	@echo "\e[1;32m[compiling "$(MODE)" {"$(CC)"}...]\e[1;00m "$<
	@$(CC) $(CFLAGS) $(COPTS) -c $< -o $@

all:		libft $(NAME)

libft:
	@make -C third_party/libft

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

.PHONY:		all clean fclean re norminette libft 
