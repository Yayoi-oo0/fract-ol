CC  = gcc
CFLAGS    = -Wall -Wextra -Werror -Iincludes
NAME    = libft.a
INCLUDE = -I ../../includes/
OBJS_DIR = objs/

SRCS    = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

SRCSB = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

REG_OBJ_FILES = $(SRCS:.c=.o)
BONUS_OBJ_FILES = $(SRCSB:.c=.o)


OBJS    = $(addprefix $(OBJS_DIR), $(REG_OBJ_FILES))
ifdef WITH_BONUS
OBJS    += $(addprefix $(OBJS_DIR), $(BONUS_OBJ_FILES))
endif

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

clean:
	rm -rf $(OBJS_DIR)
fclean:clean
	rm -f $(NAME)
re: fclean all
bonus: 
	@make WITH_BONUS=1
.PHONY: clean all fclean re bonus
