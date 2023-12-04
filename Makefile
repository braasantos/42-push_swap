#---------------VARIAVEIS-----------#
NAME = push_swap

SRCS = push_swap.c 

HEADER = push_swap.h

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra 
COMPILER = $(CC) $(CFLAGS)
RM = rm -f

#------------REGRAS--------------#
# compiles the project
all: $(NAME)

%.o : %.c 
	$(COMPILER) -c $< -o $@

$(NAME): $(OBJS)
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
.SILENT:
