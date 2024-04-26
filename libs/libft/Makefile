NAME = libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

AR = ar -rcs

SRC = ft_strncmp.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_split.c \
		ft_substr.c \
		ft_putstr.c \
		ft_strlen.c

OBJECTS = $(SRC:%.c=%.o)

BONUS_OBJECTS = $(BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I ../../include -c $< -o $@

$(NAME): $(OBJECTS)
		$(AR) $(NAME) $(OBJECTS)

bonus:	$(BONUS_OBJECTS)
	ar rcs $(NAME) $(BONUS_OBJECTS)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: fclean re all clean
