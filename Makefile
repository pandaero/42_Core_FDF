# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 23:15:27 by pandalaf          #+#    #+#              #
#    Updated: 2022/10/05 18:19:04 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target output
NAME := fdf
BONUS_NAME := fdf_bonus
# Compiler options
CC := cc
CFLAGS := -Wall -Werror -Wextra
COPTIONS :=
# Libft location
LIBFT := libft.a
LIBFT_PATH := libft/
LIBFT_FULL = $(addprefix $(LIBFT_PATH), $(LIBFT))
# Minilibx
MLX := libmlx_Linux.a
MLX_PATH := minilibx-linux/
MLX_FULL = $(addprefix $(MLX_PATH), $(MLX))
# Sources identification
SRC_DIR := src/
SRC_FILES := fdf.c map_reader.c utils.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
BSRC_DIR := src/bonus/
BSRC_FILES :=
BSRCS := $(addprefix $(BSRC_DIR), $(BSRC_FILES))
# Object identification (not necessary)
#OBJ_DIR := obj/
#OBJS := $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
#BOBJS := $(addprefix $(OBJ_DIR), $(BSRC_FILES:.c=.o))
# OS-Specific differences
OS = $(shell uname)
ifeq ($(OS), Linux)
	LIBS += -lX11 -lXext 
endif
ifeq ($(OS), Darwin)
	LIBS += -Lmlx -lmlx -framework OpenGL -framework AppKit
	SRCS_NAMES += destroy_mac
endif

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(COPTIONS) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT_FULL) $(MLX_FULL)

bonus: $(BOBJS) $(LIBFT)
	$(CC) $(COPTIONS) $(CFLAGS) -o $(BONUS_NAME) $(BSRCS) $(SRCS)\
	$(LIBFT_FULL) $(MLX_FULL)

# Make complete libft with bonus
$(LIBFT): $(LIBFT_PATH)
	make -C $(LIBFT_PATH) bonus

$(MLX): $(MLX_PATH)
	make -C $(MLX_PATH) all

$(addprefix $(OBJ_DIR), %.o): %.c | $(OBJ_DIR)
	$(CC) $(COPTIONS) $(CFLAGS) $^ -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -fr $(OBJ_DIR)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all bonus clean fclean re