CC = cc

CFLAGS = -Wall -Wextra -Werror -I./includes/

RM = rm -rf

NAME = libftprintf.a

SRCS = srcs/core/ft_printf.c \
       srcs/utils/ft_print_char.c \
       srcs/utils/ft_print_string.c \
       srcs/utils/ft_strlen.c
	   
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	$(CC) $(CFLAGS) main.c $(NAME) -o test
	./test

.PHONY: all clean fclean re test