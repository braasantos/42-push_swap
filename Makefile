#---------------VARIAVEIS-----------#
NAME = push_swap.a

SRCS =
LIBFT_PATH = /42 Cursus/LIBFT

HEADER = push_swap.h

OBJS = $(SRCS:.c=.o)
OBJSB = $(BONUS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra 
COMPLIER = $(CC) $(CFLAGS)
RM = rm -f
#------------REGRAS--------------#
#compila o projeto
all: $(NAME)

%.o : %.c 
	$(COMPLIER) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)

#limpa os arquivos criados na compilacao
clean:
	$(RM) $(OBJS)

#limpa os arquivos criados e mas tambem a biblioteca estatica
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
# .SILENT:
