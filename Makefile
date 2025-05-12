# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okamotoyayoi <okamotoyayoi@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 17:11:07 by okamotoyayo       #+#    #+#              #
#    Updated: 2025/05/12 16:10:03 by okamotoyayo      ###   ########.fr        #
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
MLX_TAR = minilibx-linux.tgz
MLX_FLAGS = -L/opt/X11/lib -lX11 -lXext -L$(MLX_DIR) -lm -lmlx
MLX 	= $(MLX_DIR)/libmlx.a $(MLX_DIR)/libmlx_Linux.a

SRC_FILES = main.c \

OBJ_FILES	= $(addprefix $(OBJS_DIR), $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJ_FILES)
	@$(MAKE) -C $(LIBFT_DIR)/src/$(PRINTF_DIR)/
	@$(CC) -g $(CFLAGS) $(OBJ_FILES) -o $(NAME) -L$(LIBFT_DIR)/src/$(PRINTF_DIR)/ -lftprintf


$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(MLX_TAR):
	curl -O $(MLX_URL)
	@tar -xzf $(MLX_TAR)
	$(MAKE) -j4 -C $(MLX_DIR)



clean:
	@$(MAKE) -C $(LIBFT_DIR)/src/$(PRINTF_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@rm -rf $(OBJS_DIR)

fclean:
	@$(MAKE) -C $(LIBFT_DIR)/src/$(PRINTF_DIR) fclean
	@$(MAKE) clean
	@rm -f $(NAME)
	@rm -f $(LIBFTPRINTF)
	@rm -f $(MLX_TAR)
	@rm -rf $(MLX_DIR)

re: fclean all

.PHONY: clean all fclean re