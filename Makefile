
SRC=ft_putnbr.c\
ft_hexconv.c\
ft_putstr.c \
ft_putchar.c \
ft_printf.c \
ft_print_str.c \

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a
CC = gcc -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
%.o: %.c 
	$(CC) -c $< -o $@
clean: 
	$(RM) $(OBJ)
fclean:
	$(RM) $(NAME) $(OBJ)
re: fclean all
.PHONY: all, clean, fclean,