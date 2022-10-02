# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 23:15:27 by pandalaf          #+#    #+#              #
#    Updated: 2022/10/02 00:00:48 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target output
NAME := fdf
BONUS_NAME := fdf_bonus
# Compiler options
CC := cc
CFLAGS := -Wall -Werror -Wextra
COPTIONS := -c
# Libft location
LIBFT := libft.a
LIBFT_PATH := libft/
LIBFT_FULL = $(addprefix $(LIBFT_PATH), $(LIBFT))
# Sources identification
SRC_DIR := src/
SRCS_FILES := map_reader.c
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))
BSRC_DIR := src/bonus/
BSRCS_FILES :=
BSRCS := $(addprefix $(BSRC_DIR), $(BSRCS_FILES))
# Object identification
OBJ_DIR := obj/
OBJS := $(addprefix $(OBJ_DIR), $(SRCS_FILES:.c=.o))
BOBJS := $(addprefix $(OBJ_DIR), $(BSRCS_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(COPTIONS) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT_FULL)

bonus: $(BOBJS) $(OBJS) $(LIBFT)
	$(CC) $(COPTIONS) $(CFLAGS) -o $(BONUS_NAME) $(BSRCS) $(SRCS) $(LIBFT_FULL)

# Make complete libft with bonus
$(LIBFT): $(LIBFT_PATH)
	make -C $(LIBFT_PATH) bonus

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