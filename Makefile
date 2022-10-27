# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 23:15:27 by pandalaf          #+#    #+#              #
#    Updated: 2022/10/27 19:49:07 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target output
NAME := fdf
BONUS_NAME := fdf_bonus
# Compiler options
CC := cc
CFLAGS := -Wall -Werror -Wextra
COPTIONS := -g
# Libft location
LIBFT := libft.a
LIBFT_PATH := libft/
LIBFT_FULL = $(addprefix $(LIBFT_PATH), $(LIBFT))
# Minilibx
MLX := libmlx_Darwin.a
MLX_PATH := minilibx-linux/
MLX_FULL = $(addprefix $(MLX_PATH), $(MLX))
# Libs and frameworks for compilation
LIBS := -lmlx -framework OpenGL -framework AppKit
# Sources identification
SRC_DIR := src/
SRC_FILES := fdf.c map_reader.c draw.c draw_grid.c projection.c utils.c \
				quick_pixel.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
# Bonus sources identification
BSRC_DIR := src/bonus/
BSRC_FILES := fdf_bonus.c utils_bonus.c draw_grid_bonus.c map_bonus.c \
			projection_bonus.c transformation_bonus.c \
			../map_reader.c ../draw.c ../draw_grid.c ../quick_pixel.c \
			../projection.c ../utils.c
BSRCS := $(addprefix $(BSRC_DIR), $(BSRC_FILES))

# Make desired targets
all: $(NAME)

# Make target executable
$(NAME): $(SRCS) $(LIBFT_FULL) $(MLX_FULL)
	$(CC) $(COPTIONS) $(CFLAGS) $(LIBS) -o $(NAME) $(SRCS) $(LIBFT_FULL) \
	$(MLX_FULL)

# Make bonus executable
bonus: $(BSRCS) $(LIBFT_FULL) $(MLX_FULL)
	$(CC) $(COPTIONS) $(CFLAGS) $(LIBS) -o $(BONUS_NAME) $(BSRCS) \
	$(LIBFT_FULL) $(MLX_FULL)

# Make Libft archive
$(LIBFT_FULL): $(LIBFT_PATH)
	make -C $(LIBFT_PATH) bonus

# Make MLX archive
$(MLX_FULL): $(MLX_PATH)
	make -C $(MLX_PATH) all

# Clean intermediate files
clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

# Clean all non-source files
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_PATH) fclean

# Clean everything and make again
re: fclean all

# Make sure these aren't treated as filenames
.PHONY: all bonus clean fclean re
