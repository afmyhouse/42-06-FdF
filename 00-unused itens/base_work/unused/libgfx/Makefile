# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 21:39:14 by antoda-s          #+#    #+#              #
#    Updated: 2023/10/09 21:41:16 by antoda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# my own gfx tools for fdf compiled into a library

NAME = libgfx.a

FILES +=	color.c			# color table
FILES =		draw.c			# Draw points and lines
FILES +=	image.c			# easier image creation
FILES +=	matrix.c		# Matrix functions: bzero id mult scale trans
FILES +=	matrix_rot.c	# Matrix functions:
FILES +=	toggle_keys.c
FILES +=	vertex.c		# Vertex creation:

FLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(addprefix build/, $(FILES:.c=.o))

GFX = -I .
FT = -I ../libft
MLX = -I ../minilibx

.PHONY: all re clean fclean

all: $(NAME)

re: fclean all

clean:
	rm -rf build

fclean: clean
	rm -rf $(NAME)

build:
	mkdir build/

$(NAME): $(OBJS)
	@echo "Making $@"
	ar rcs $(NAME) $(OBJS)

build/%.o: srcs/%.c | build
	@echo "Building $@"
	gcc $(FLAGS) $(FT) $(MLX) $(GFX) -c $< -o $@
