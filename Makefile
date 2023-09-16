# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 14:52:10 by antoda-s          #+#    #+#              #
#    Updated: 2023/09/16 12:31:04 by antoda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable File Name(s):
M_NAME = fdf
B_NAME = fdf_bonus
#EXTRA_FILE = moves.txt
#Compiling Variables:
CC 			= cc
# without the debug flag -g
CFLAGS		= -Wall -Werror -Wextra
CF_MLX_NAME	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
CF_MLX_O	= -I/usr/include -Imlx_linux -O3
#all compiler flags
C_ALL	= cc -Wall -Werror -Wextra -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz main.c -o main
# with debug flag -g
# CFLAGS 		= -Wall -Werror -Wextra -g
RM			= rm -rf

# Decide whether the commands will be shwon or not
VERBOSE = TRUE

#Directory paths when compiling and required:
# If Makefile if 1 folder belowproject directory
# PROJDIR 	:= $(realpath $(CURDIR)/..)
# If Makefile if in the same folder as the project directory
PROJDIR 	:= $(realpath $(CURDIR))
DSRC		:= src
DSRC_M		:= src/fdf
DSRC_C		:= src/common
DSRC_B		:= src/fdf_bonus
DBIN		:= bin
DINC		:= src/inc
DLIB		:= libft
DMLX		:= mlx_linux
# VPATH 		= $(DSRC)

#functions & variables libraries:
LIBFT 		= $(DLIB)/libft.a
# INcluding HEADER files:
INCLUDES	= -I $(DINC)
#INCLUDES	= -I $(DINC) -I $(DLIB)

#Sources
#M_SRCS 		= $(DSRC_M)/fdf.c
M_SRCS 		= $(DSRC_M)/main.c

C_SRCS 		= $(DSRC_C)/fdfc.c

B_SRCS		= $(DSRC_B)/fdfb.c

#Objects
M_OBJS		:= $(subst $(DSRC_M),$(DBIN),$(M_SRCS:.c=.o))
C_OBJS		:= $(subst $(DSRC_C),$(DBIN),$(C_SRCS:.c=.o))
B_OBJS		:= $(subst $(DSRC_B),$(DBIN),$(B_SRCS:.c=.o))

#Rules:

# Hide or not the calls depending of VERBOSE
ifeq ($(VERBOSE),TRUE)
    HIDE =
else
    HIDE = @
endif

#Colors:
GRN		=	\e[38;5;118m
YLW		=	\e[38;5;226m
RED		=	\e[38;5;196m
BLU		=	\e[38:5:31m
WTH		=	\e[0m
CYN		:= \033[1;36m
RESET	:= \033[0m
BOLD	:= \033[1m

_INFO		=	[$(YLW)INFO$(WTH)]
_SUCCESS	=	[$(GRN)DONE$(WTH)]

#Rules:

# This is the MANDATORY target invoked with >make m
m: $(M_NAME)

# This is the GLOBAL target invoked with >make all
all: m bonus

# This is the BONUS target invoked with >make b
bonus: $(B_NAME)

#MANDATORY
$(M_NAME): $(LIBFT) $(MINILIBX) $(M_OBJS) $(C_OBJS)
	@echo "$(_INFO)"
	@$(CC) $(CFLAGS) $(M_OBJS) $(C_OBJS) $(CF_MLX_NAME) $(INCLUDES) $(LIBFT) -o $@
	@echo "[$(BLU)Compiling $(BOLD)MANDATORY$(RESET) $(GRN)$(@) $(BLU)file$(WTH)] $(_SUCCESS)"
	@echo
#BONUS
$(B_NAME): $(LIBFT) $(MINILIBX) $(B_OBJS) $(C_OBJS)
	@echo "$(_INFO)"
	@$(CC) $(CFLAGS) $(B_OBJS) $(C_OBJS) $(CF_MLX_NAME) $(INCLUDES) $(LIBFT) -o $@
	@echo "[$(BLU)Compiling BONUS $(GRN)$(@) $(BLU)file$(WTH)] $(_SUCCESS)"
	@echo

#MY OWN LIBRARY
$(LIBFT):
	@echo "$(_INFO)"
	@echo "[$(BLU)Compile Libft$(WTH)]"
	@$(MAKE) --no-print-directory -C $(DLIB)
	@echo "$(_SUCCESS)"
	@echo

$(MINILIBX):
	@echo "$(_INFO)"
	@echo "[$(BLU)Compile Minilibx$(WTH)]"
	@$(MAKE) --no-print-directory -C $(DMLX)
	@echo "$(_SUCCESS)"
	@echo

#OBJECTS
$(M_OBJS): $(DBIN)/%.o: $(DSRC_M)/%.c
	@mkdir -p $(DBIN)
	@$(CC) $(CFLAGS) $(CF_MLX_O) -c $< -o $@
	@echo "[$(BLU)Compile Mandatory Objectos$(WTH)] : $< $(_SUCCESS)"

$(C_OBJS): $(DBIN)/%.o: $(DSRC_C)/%.c
	@mkdir -p $(DBIN)
	@$(CC) $(CFLAGS) $(CF_MLX_O) -c $< -o $@
	@echo "[$(BLU)Compile Common Objects$(WTH)] : $< $(_SUCCESS)"

$(B_OBJS): $(DBIN)/%.o: $(DSRC_B)/%.c
	@mkdir -p $(DBIN)
	@$(CC) $(CFLAGS) $(CF_MLX_O) -c $< -o $@
	@echo "[$(BLU)Compile BONUS Objects$(WTH)] : $< $(_SUCCESS)"

#UTILITIES
clean: cleanlibft
	@echo "$(_INFO)"
	@echo "[$(RED)Cleaning MANDATORY Objects$(WTH)]"
	@$(RM) $(M_OBJS)
	@echo "$(M_OBJS) file removed!!"
	@echo "[$(RED)Cleaning COMOON Objects$(WTH)]"
	@$(RM) $(C_OBJS)
	@echo "$(C_OBJS) file removed!!"
	@echo "[$(RED)Cleaning BONUS Objects$(WTH)]"
	@$(RM) $(B_OBJS)
	@echo "$(B_OBJS) file removed!!"
	@$(RM) $(EXTRA_FILE)
	@echo "$(EXTRA_FILE) file removed!!"
	@echo "$(_SUCCESS)"
	@echo

cleanlibft:
	@echo "$(_INFO)"
	@echo "[$(RED)Project : Cleaning Libft objs$(WTH)]"
	@$(MAKE) clean --no-print-directory -C $(DLIB)
	@echo "$(_SUCCESS)"
	@echo

fclean: clean
	@echo "$(_INFO)"
	@echo "[$(RED)Project : Cleaning Libft.a$(WTH)]"
	@$(MAKE) fclean --no-print-directory -C $(DLIB)
	@echo "$(_SUCCESS)"
	@echo
	@echo "$(_INFO)"
	@echo "[$(RED)Clean Project executables files$(WTH)]"
	@$(RM) $(M_NAME)
	@echo "$(M_NAME) file removed!!"
	@$(RM) $(B_NAME)
	@echo "$(B_NAME) file removed!!"
	@echo "$(_SUCCESS)"
	@echo

re: fclean all

show:
	@echo "$(YLW)[ALL PATHS  ]$(WTH) *invoked with > make show*"
	@echo ""
	@echo "$(YLW)[LIB DIR  = ]$(WTH)$(BLU) $(DLIB)$(WTH) $(YLW)]$(WTH)"
	@echo "$(YLW)[LIB FILE = ]$(WTH) $(LIBFT) $(YLW)]$(WTH)"
	@echo ""
	@echo "$(YLW)[COMMON    SRC DIR 	= $(WTH) $(BLU)$(DSRC_C) $(YLW)]$(WTH)"
	@echo "$(YLW)[COMMON    SRC FILES	= $(WTH) $(notdir $(C_SRCS)) $(YLW)]$(WTH)"
	@echo ""
	@echo "$(YLW)[MANDATORY SRC DIR 	= $(WTH) $(BLU)$(DSRC_M) $(YLW)]$(WTH)"
	@echo "$(YLW)[MANDATORY SRC FILE	= $(WTH) $(notdir $(M_SRCS)) $(YLW)]$(WTH)"
	@echo "$(YLW)[MANDATORY TARGET DIR	= $(WTH) $(BLU)$(CURDIR) $(YLW)]$(WTH)"
	@echo "$(YLW)[MANDATORY TARGET FILE	= $(WTH) $(notdir $(M_NAME)) $(YLW)]$(WTH)"
	@echo ""
	@echo "$(YLW)[BONUS 	SRC DIR 	= $(WTH) $(BLU) $(DSRC_B) $(YLW)]$(WTH)"
	@echo "$(YLW)[BONUS 	SRC FILES 	= $(WTH) $(notdir $(B_SRCS)) $(YLW)]$(WTH)"
	@echo "$(YLW)[BONUS 	TARGET DIR 	= $(WTH) $(BLU)$(CURDIR) $(YLW)]$(WTH)"
	@echo "$(YLW)[BONUS 	TARGET FILE = $(WTH) $(notdir $(B_NAME)) $(YLW)]$(WTH)"
	@echo ""
	@echo "$(YLW)[GLOBAL OBJS DIR 	= $(WTH)$(BLU) $(DBIN)$(WTH) $(YLW)]$(WTH)"
	@echo "$(YLW)[MANDATORY OBJS FILE 	= $(WTH) $(notdir $(M_OBJS)) $(YLW)]$(WTH)"
	@echo "$(YLW)[COMMON OBJS FILE 	= $(WTH) $(notdir $(C_OBJS)) $(YLW)]$(WTH)"
	@echo "$(YLW)[BONUS 	OBJS FILE 	= $(WTH) $(notdir $(B_OBJS)) $(YLW)]$(WTH)"

# Every target that is not a file is identified on .PHONY
.PHONY: all clean fclean re show m b cleanlibft
# To SLICENCE the activity except echo commands, add @ before the command
#.SILENT: