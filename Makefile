# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 23:15:27 by pandalaf          #+#    #+#              #
#    Updated: 2022/10/07 09:34:01 by pandalaf         ###   ########.fr        #
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
MLX := libmlx42.a
MLX_PATH := mlx42/
MLX_FULL = $(addprefix $(MLX_PATH), $(MLX))
# Sources identification
SRC_DIR := src/
SRC_FILES := fdf.c map_reader.c draw.c draw_grid.c project.c utils.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
BSRC_DIR := src/bonus/
BSRC_FILES := fdf_bonus.c
BSRCS := $(addprefix $(BSRC_DIR), $(BSRC_FILES))
# Object identification (not necessary)
#OBJ_DIR := obj/
#OBJS := $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
#BOBJS := $(addprefix $(OBJ_DIR), $(BSRC_FILES:.c=.o))
# OS-Specific differences
OS = $(shell uname)
ifeq ($(OS), Linux)
	LIBS += -lglfw -lm
endif
ifeq ($(OS), Darwin)
	LIBS += -I include -lglfw -L "/Users/$USER/.brew/opt/glfw/lib/"
endif

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(MLX)
	$(CC) $(COPTIONS) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT_FULL) $(MLX_FULL) \
	$(LIBS)

bonus: $(BSRCS) $(LIBFT) $(MLX)
	$(CC) $(COPTIONS) $(CFLAGS) -o $(BONUS_NAME) $(BSRCS) $(SRCS) \
	$(LIBFT_FULL) $(MLX_FULL) $(LIBS)

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
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
	make -C $(MLX_PATH) fclean

re: fclean all

.PHONY: all bonus clean fclean re