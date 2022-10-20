# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 23:15:27 by pandalaf          #+#    #+#              #
#    Updated: 2022/10/20 19:48:05 by pandalaf         ###   ########.fr        #
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
MLX := libmlx_Darwin.a
MLX_PATH := minilibx-linux/
MLX_FULL = $(addprefix $(MLX_PATH), $(MLX))
# Libs and frameworks
LIBS := -lmlx -framework OpenGL -framework AppKit
# Sources identification
SRC_DIR := src/
SRC_FILES := fdf.c map_reader.c draw.c draw_grid.c project.c utils.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
BSRC_DIR := src/bonus/
BSRC_FILES := fdf_bonus.c
BSRCS := $(addprefix $(BSRC_DIR), $(BSRC_FILES))


all: $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(MLX)
	$(CC) $(COPTIONS) $(CFLAGS) $(LIBS) -o $(NAME) $(SRCS) $(LIBFT_FULL) \
	$(MLX_FULL)

bonus: $(BSRCS) $(LIBFT) $(MLX)
	$(CC) $(COPTIONS) $(CFLAGS) -o $(BONUS_NAME) $(BSRCS) $(SRCS) \
	$(LIBFT_FULL) $(MLX_FULL) $(LIBS)

$(LIBFT): $(LIBFT_PATH)
	make -C $(LIBFT_PATH) bonus

$(MLX): $(MLX_PATH)
	make -C $(MLX_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
	make -C $(MLX_PATH) fclean

re: fclean all

.PHONY: all bonus clean fclean re