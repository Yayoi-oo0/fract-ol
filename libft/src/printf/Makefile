CC  = gcc
CFLAGS    = -Wall -Wextra -Werror
NAME    = libftprintf.a
INCLUDE = -I ../../includes/
OBJS_DIR = objs/

SRCS    = ft_printf.c \
		ft_check.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_putunbr.c \
		ft_puthex.c \
		ft_putptr.c \
		ft_putchar.c \
		ft_itoa_base.c  

REG_OBJ_FILES = $(SRCS:.c=.o)

OBJS    = $(addprefix $(OBJS_DIR), $(REG_OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(MAKE) -C ../std_libft/
	cp ../std_libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

clean:
	make fclean -C ../std_libft/
	rm -rf $(OBJS_DIR)
	
fclean:clean
	rm -f $(NAME)
re: fclean all
.PHONY: clean all fclean re