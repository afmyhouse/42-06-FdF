# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 21:23:27 by antoda-s          #+#    #+#              #
#    Updated: 2023/11/07 12:46:23 by antoda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fdf
NAMEB 		= fdf_bonus
MLX 		= minilibx.a
LIBFT 		= libft.a
GFX 		= libgfx.a

LFT_PATH 	= ./libft/
GFX_PATH 	= ./libgfx/
MLX_PATH 	= ./minilibx-linux/
INCLUDES 	= ./include/
SRCDIRM 	= srcsm/
OBJSDIRM 	= buildm/
SRCDIRB 	= srcsb/
OBJSDIRB 	= buildb/


FILES	=	main.c
FILES	+=	fdf.c			# Top level fdf functions
FILES	+=	fdf_exit.c		# view and local_to_world_to_aligned_to_projected
FILES	+=	fdf_init_k.c		# view and local_to_world_to_aligned_to_projected
FILES	+=	fdf_init.c		# view and local_to_world_to_aligned_to_projected
FILES	+=	fdf_plot.c		# Connect the vertexs with lines
FILES	+=	fdf_vertex.c	# view and local_to_world_to_aligned_to_projected
FILES	+=	parse_file.c	# Parse out the map files into vertexs
FILES	+=	hooks.c			# Loop, exit, expose and key hooks
FILES	+=	hooks_scale.c	# Zoom (full) and Axys Scale setup
FILES	+=	hooks_colors.c	# Colors Z based setup
FILES	+=	toggle_keys.c	# key toggle management

FILESB	=	main_bonus.c
FILESB	+=	fdf_bonus.c			# Top level fdf functions
FILESB	+=	fdf_exit_bonus.c		# view and local_to_world_to_aligned_to_projected
FILESB	+=	fdf_init_k_bonus.c	# view and local_to_world_to_aligned_to_projected
FILESB	+=	fdf_init_bonus.c		# view and local_to_world_to_aligned_to_projected
FILESB	+=	fdf_plot_bonus.c		# Connect the vertexs with lines
FILESB	+=	fdf_show_data_bonus.c	# view and local_to_world_to_aligned_to_projected
FILESB	+=	fdf_show_k_bonus.c	# view and local_to_world_to_aligned_to_projected
FILESB	+=	fdf_show_vx_bonus.c	# view and local_to_world_to_aligned_to_projected
FILESB	+=	fdf_vertex_bonus.c	# view and local_to_world_to_aligned_to_projected
FILESB	+=	parse_file_bonus.c	# Parse out the map FILESB into vertexs
FILESB	+=	hooks_bonus.c			# Loop, exit, expose and key hooks
FILESB	+=	hooks_scale_bonus.c	# Zoom (full) and Axys Scale setup
FILESB	+=	hooks_shift_bonus.c	# Translate value setup
FILESB	+=	hooks_colors_bonus.c	# Colors Z based setup
FILESB	+=	hooks_zoom_bonus.c	# Colors Z based setup
FILESB	+=	hooks_rotation_bonus.c# Rotation angle stup
FILESB	+=	toggle_keys_bonus.c	# key toggle management


SRCM = $(addprefix $(SRCDIRM), $(FILES))
OBJM = $(addprefix $(OBJSDIRM), $(FILES:.c=.o))

SRCB = $(addprefix $(SRCDIRB), $(FILESB))
OBJB = $(addprefix $(OBJSDIRB), $(FILESB:.c=.o))

#compilation
CF 			= -Wall -Wextra -Werror -g
CC 			= cc
MLX_CF 		= -lm -lX11 -lXext
I_HEADER	= -I include
I_MLX 		= -I minilibx
I_LIBFT 	= -I libft
I_GFX 		= -I libgfx
LNK_LIBFT 	= -L $(LFT_PATH) -lft
LNK_MLX 	= -L $(MLX_PATH) -lmlx
LNK_GFX 	= -L $(GFX_PATH) -lgfx

LEAKS 		= valgrind
LEAKS_FILE	= valgrind-log.txt
LF 			= --leak-check=full \
        		--show-leak-kinds=all \
        		--track-origins=yes \
        		--verbose \
        		--log-file=$(LEAKS_FILE) \
        		./fdf maps/42.fdf

#common commands
RM =rm -f

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



#rules
all: $(NAME)

$(NAME): $(GFX) $(LIBFT) $(MLX) $(OBJM)
	@printf "$(GRN)Objects ready!$(WTH)\n\n"
	@printf "\n$(CYN)Generating FdF executable...$(WTH)\n"
	$(CC) $(CF) $(OBJM) $(LNK_LIBFT) $(LNK_GFX) $(LNK_MLX) $(MLX_CF) -o $@
	@printf "$(GRN)Done!$(WTH)\n\n"

$(NAMEB): $(GFX) $(LIBFT) $(MLX) $(OBJB)
	@printf "$(GRN)Objects ready!$(WTH)\n\n"
	@printf "\n$(CYN)Generating FdF executable...$(WTH)\n"
	$(CC) $(CF) $(OBJB) $(LNK_LIBFT) $(LNK_GFX) $(LNK_MLX) $(MLX_CF) -o $@
	@printf "$(GRN)Done!$(WTH)\n\n"

build:
	@mkdir -p $(OBJSDIRM)
	@printf "\n$(CYN)Compiling source files...$(WTH)\n"

buildb:
	@mkdir -p $(OBJSDIRB)
	@printf "\n$(CYN)Compiling source files...$(WTH)\n"

$(OBJSDIRM)%.o: $(SRCDIRM)%.c | build
	$(CC) $(CF) -c $(I_GFX) $(I_MLX) $(I_LIBFT) $(I_HEADER) $< -o $@

$(OBJSDIRB)%.o: $(SRCDIRB)%.c | buildb
	$(CC) $(CF) -c $(I_GFX) $(I_MLX) $(I_LIBFT) $(I_HEADER) $< -o $@

$(MLX):
	@printf "\n$(CYN)Generating MiniLibX...$(WTH)\n"
	@make -C $(MLX_PATH)
	@printf "$(GRN)MiniLibX created!$(WTH)\n\n"

$(LIBFT):
	@printf "\n$(GRN)Generating Libft...$(WTH)\n"
	@make -C $(LFT_PATH)
	@printf "$(GRN)Libft created!$(WTH)\n\n"

$(GFX):
	@printf "\n$(GRN)Generating Libgfx...$(WTH)\n"
	@make -C $(GFX_PATH)
	@printf "$(GRN)Libgfx created!$(WTH)\n\n"

bonus: $(NAMEB)

re: fclean all

rebonus: fclean bonus

leaks:
	$(LEAKS) $(LF)
	@printf "$(GRN)Leaks log ready! Check valgrind-out.txt $(WTH)\n\n"

cleanleaks:
	$(RM) $(LEAKS_FILE)
	@printf "$(GRN)Leaks log file deleted.$(WTH)\n\n"

clean:
	@printf "\n$(YLW)Cleaning all object files from project...$(WTH)\n"
	$(RM) -rf $(OBJM) $(OBJSDIRM)
	$(RM) -rf $(OBJB) $(OBJSDIRB)

fclean: clean
	@printf "\n$(YLW)Cleaning all additional objects and libraries...$(WTH)\n"
	$(RM) -rf $(NAME)
	$(RM) -rf $(NAMEB)
	@make fclean -C $(LFT_PATH)
	@make fclean -C $(GFX_PATH)
	@make clean -C $(MLX_PATH)
	@printf "$(GRN)All libraries removed!$(WTH)\n\n"
	make cleanleaks

install:
	sudo apt-get install gcc make xorg libxext-dev libbsd-dev -y
	@printf "$(GRN)All dependencies ready!$(WTH)\n\n"

.PHONY: clean fclean re rebonus all bonus build

show:
	@echo "$(YLW)[ALL PATHS  ]$(WTH) *invoked with > make show*"
	@echo ""
	@echo "$(YLW)[LIB DIR  = ]$(WTH)$(BLU) $(LFT_PATH)$(WTH) $(YLW)]$(WTH)"
	@echo "$(YLW)[LIBFT FILE = ]$(WTH) $(LIBFT) $(YLW)]$(WTH)"
	@echo "$(YLW)[LIB DIR  = ]$(WTH)$(BLU) $(GFX_PATH)$(WTH) $(YLW)]$(WTH)"
	@echo "$(YLW)[LIGFX FILE = ]$(WTH) $(LIGFX) $(YLW)]$(WTH)"
	@echo "$(YLW)[LIB DIR  = ]$(WTH)$(BLU) $(MLX_PATH)$(WTH) $(YLW)]$(WTH)"
	@echo "$(YLW)[LIBMLX FILE = ]$(WTH) $(MLX) $(YLW)]$(WTH)"
	@echo ""
	@echo "$(YLW)[MANDATORY SRC DIR 	= $(WTH) $(BLU)$(SRCDIRM) $(YLW)]$(WTH)"
	@echo "$(YLW)[MANDATORY SRC FILE	= $(WTH) $(notdir $(FILES)) $(YLW)]$(WTH)"
	@echo "$(YLW)[MANDATORY TARGET DIR	= $(WTH) $(BLU)$(CURDIR) $(YLW)]$(WTH)"
	@echo "$(YLW)[MANDATORY TARGET FILE	= $(WTH) $(notdir $(NAME)) $(YLW)]$(WTH)"
	@echo ""
	@echo "$(YLW)[GLOBAL OBJS DIR 	= $(WTH)$(BLU) $(OBJDIRM)$(WTH) $(YLW)]$(WTH)"
	@echo "$(YLW)[MANDATORY OBJS FILE 	= $(WTH) $(notdir $(OBJM)) $(YLW)]$(WTH)"
	@echo ""
