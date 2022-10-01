# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 23:15:27 by pandalaf          #+#    #+#              #
#    Updated: 2022/10/01 18:45:40 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf
CC := cc
CFLAGS := -Wall -Werror -Wextra
COPTIONS := -c
LIBFT := libft.a
LIBFT_PATH := libft/
OBJ_DIR := obj/
SRCS :=
BSRCS :=
OBJS := $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
BOBJS := $(addprefix $(OBJ_DIR), $(BSRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(SRCS) $(addprefix $(LIBFT_PATH), $(LIBFT))

bonus: $(BOBJS) $(OBJS) $(LIBFT)
	$(CC) $(COPTIONS) $(CFLAGS) $(BSRCS) $(SRCS) $(addprefix $(LIBFT_PATH), $(LIBFT))

$(LIBFT): $(LIBFT_PATH)
	make -C $(LIBFT_PATH) bonus

$(addprefix $(OBJ_DIR), %.o): %.c | $(OBJ_DIR)
	$(CC) $(COPTIONS) $(CFLAGS) $^ -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -fr $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re