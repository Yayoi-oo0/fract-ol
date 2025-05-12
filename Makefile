# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okamotoyayoi <okamotoyayoi@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 17:11:07 by okamotoyayo       #+#    #+#              #
#    Updated: 2025/05/01 17:42:18 by okamotoyayo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC  = gcc
CFLAGS    = -Wall -Wextra -Werror
NAME    = fractol

SRCS_DIR = src/
OBJS_DIR = objs/
LIBFT_DIR = libft/
PRINTF_DIR = printf/
LIBFTPRINTF = libftprintf.a

INCLUDE = -I include/ -I $(LIBFT_DIR)includes/

MLX_DIR = minilibx-linux
MLX_URL = https://cdn.intra.42.fr/document/document/32190/minilibx-linux.tgz
MLX_LIB = minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a
MLX_TAR = minilibx-linux.tgz
MLX_FLAGS = -L/opt/X11/lib -lX11 -lXext -L$(MLX_DIR) -lm -lmlx

SRC_FILES = 

OBJ_FILES	= $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS_DIR)fractol.o
	@$(MAKE) -C $(LIBFT_DIR)/src/$(PRINTF_DIR)/
	@$(CC) -g $(CFLAGS) $(OBJS_DIR)fractol.o -o $(C_NAME) -L$(LIBFT_DIR)/src/$(PRINTF_DIR)/ -lftprintf


$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	@$(MAKE) -C $(LIBFT_DIR)/src/$(PRINTF_DIR) clean
	@rm -rf $(OBJS_DIR)

fclean:
	@$(MAKE) -C $(LIBFT_DIR)/src/$(PRINTF_DIR) fclean
	@$(MAKE) clean
	@rm -f $(NAME)
	@rm -f $(LIBFTPRINTF)

re: fclean all

.PHONY: clean all fclean re