#---------------VARIAVEIS-----------#
NAME = push_swap
SRCS = push_swap.c operations_b.c operations_a.c utils_2.c utils.c rota.c stacks.c stacks_2.c last.c checkers.c ft_split.c
INC = push_swap.h
LIBFT = ./libft/libft.a
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d) 
CC = cc
CFLAGS = -Wall -Werror -Wextra 
COMPILER = $(CC) $(CFLAGS)
RM = rm -f

#------------REGRAS--------------#
# compiles the project
all: $(NAME)

%.o: %.c
	$(COMPILER) -MMD -MF $(@:.o=.d) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Created objs daddy"
	$(COMPILER) $(OBJS) $(LIBFT) -o $(NAME)

# cleans the object files
clean:
	$(RM) $(OBJS) $(DEPS)

# cleans the object files and the executable
fclean: clean
	@echo "Deleted objs daddy"
	$(RM) $(NAME)

# cleans and rebuilds the project
re: fclean all

.PHONY: all clean fclean re
.SILENT:
