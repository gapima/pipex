
NAME = libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

AR = ar -rcs

OBJECTSDIR = obj/

SRC = ft_strlen.c \
		ft_strrchr.c \
		ft_strjoin.c \
		ft_printf.c \
		ft_printf_utils.c \
		ft_printf_utils2.c \
		get_next_line.c \
		ft_calloc.c \
		ft_bzero.c \
		ft_memset.c \
		ft_strncmp.c \
		ft_strlcpy.c \
		ft_memcpy.c \
		ft_itoa.c \
		ft_strdup.c

OBJECTS = $(SRC:%.c=%.o)

all: create_mkdir $(NAME) 

create_mkdir:
	@mkdir -p $(OBJECTSDIR)

$(OBJECTSDIR)%.o: %.c
	@$(CC) $(FLAGS) -I ../../include -c $< -o $@

$(NAME): $(addprefix $(OBJECTSDIR), $(OBJECTS))
	@$(AR) $(NAME) $(addprefix $(OBJECTSDIR), $(OBJECTS))

clean:
	@rm -f $(addprefix $(OBJECTSDIR), $(OBJECTS))

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean re all clean