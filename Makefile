CC=clang
NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_utilsa.c ft_printf_utils.c ft_printf_lib.c ft_printf_width.c ft_printf_tools.c 
HEADER = libftprintf.h libftprintfutils.h
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) -o $(OBJS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all

bonus: all

.PHONY: all fclean clean re bonus
