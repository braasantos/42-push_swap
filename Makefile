#---------------VARIAVEIS-----------#
NAME = push_swap
SRCS = push_swap.c operations_b.c operations_a.c utils_2.c utils.c rota.c stacks.c stacks_2.c last.c checkers.c
LIBFT = libft/libft.a
LIBFT_DIR = libft/
CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
COMPILER = $(CC) $(CFLAGS)
RM = rm -f

OBJS = *.o 
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Created objs daddy"
	$(COMPILER) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE)	-C $(LIBFT_DIR)

$(OBJS): $(SRCS)
	$(COMPILER) -c $(SRCS)
# cleans the object files
clean:
	$(RM) $(OBJS) $(DEPS)

# cleans the object files and the executable
fclean: clean
	@echo "Deleted objs daddy"
	$(RM) $(NAME)

# cleans and rebuilds the project
re: fclean all
	$(MAKE)
.PHONY: all clean fclean re
.SILENT: