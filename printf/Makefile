####
NAME = libftprintf.a
SRCS = ft_printf.c ft_put_char.c ft_put_str.c ft_puthexa.c ft_putadress.c ft_put_nbr.c ft_putunsig.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = cc
COMPILER = $(CC) $(FLAGS)
RM = rm -f
HEADER = ft_printf.h
####
all: $(NAME)

%.o : %.c
	$(COMPILER) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
