NAME		= push_swap
CC			= cc #-fsanitize=address -fsanitize=leak -g3 -lm
CFLAG		= -lm
RM			= rm -rf
# MANDATORY	= push_swap.c

SOURCES = push_swap.c
OBJECTS = $(SOURCES:.c=.o)

LIBFT		= libft/libft.a
INCLUDE		= ./include/

all : $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJECTS) -lm $(LIBFT) -I $(INCLUDE) -o $(NAME)

$(LIBFT):
	make -C libft

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@ 

clean :
	@$(RM) $(OBJECTS)

fclean : clean
	@$(RM) $(NAME) checker

re : fclean all

.PHONY : all clean fclean re