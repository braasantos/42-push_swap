#---------------VARIAVEIS-----------#
NAME = push_swap
SRCS = push_swap.c operations_b.c operations_a.c utils_2.c utils.c rota.c stacks.c stacks_2.c last.c checkers.c
CC = cc
HEADER = push_swap.h
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
COMPILER = $(CC) $(CFLAGS)
RM = rm -f
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
	$(COMPILER) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	@echo "Created objs daddy"
	$(COMPILER) -o $(NAME) $(OBJS)

# cleans the object files
clean:
	$(RM) $(OBJS)

# cleans the object files and the executable
fclean: clean
	@echo "Deleted objs daddy"
	$(RM) $(NAME)

# cleans and rebuilds the project
re: fclean all
	
.PHONY: all clean fclean re
#.SILENT: