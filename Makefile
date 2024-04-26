

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -Wunreachable-code -Ofast
RM = rm -f

INC = ./include
LIBFT = ./libs/libft

HEADERS = -I $(INC)
LIBS = ./libs/libft/libft.a

FILES = src/main.c src/pipex.c src/utils.c src/free.c

OBJS = $(FILES:%.c=%.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS)	-c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "SUCCESS!!"

clean:
	@rm -rf $(OBJS)
	@make clean -C libs/libft
	@rm -rf $(LIBMLX)/build

fclean: clean
	@make fclean -C libs/libft
	@rm -rf $(LIBMLX)/build	
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
