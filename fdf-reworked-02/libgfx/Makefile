# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/23 15:36:22 by myoung            #+#    #+#              #
#    Updated: 2023/10/28 23:08:44 by antoda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgfx.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I .
AR = ar

FILES =		gfx_plot.c			# Draw points and lines
FILES +=	gfx_mx_op.c			# Matrix functions: bzero id mult scale trans
FILES +=	gfx_mx_r.c			# Matrix functions: rotation
FILES +=	gfx_vertex.c		# Vertex creation:
FILES +=	gfx_image.c			# easier image creation
FILES +=	gfx_color.c			# color table

# FLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(addprefix build/, $(FILES:.c=.o))

# GFX = -I .
FT = -I ../libft
MLX = -I ../minilibx

#Colors:
GRN		=	\e[38;5;118m
YLW		=	\e[38;5;226m
RED		=	\e[38;5;196m
BLU		=	\e[38:5:31m
WTH		=	\e[0m
CYN		:= \33[1;36m
RESET	:= \033[0m
BOLD	:= \033[1m

_INFO		=	[$(YLW)INFO$(WTH)]
_SUCCESS	=	[$(GRN)DONE$(WTH)]

all: $(NAME)

re: fclean all

clean:
	rm -rf build

fclean: clean
	rm -rf $(NAME)

build:
	mkdir build/

$(NAME): $(OBJS)
	@echo
	@echo "$(GRN)Objects ready!$(WTH)"
	@echo "Making $@"
	@echo "Creating libgfx.a"
	@$(AR) crs $@ $(OBJS)

build/%.o: srcs/%.c | build
	@echo "Building $@"
	@gcc $(FLAGS) $(FT) $(MLX) $(GFX) -c $< -o $@

.PHONY: all re clean fclean
