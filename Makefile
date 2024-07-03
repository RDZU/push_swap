# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: razamora <razamora@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 15:05:03 by razamora          #+#    #+#              #
#    Updated: 2024/07/03 00:28:01 by razamora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
CFLAG		= -Wall -Wextra -Werror
RM			= rm -rf

SOURCES = push_swap.c ksort.c move.c sort_simple.c utils.c utils_stack.c process_stack.c check_stack.c
OBJECTS = $(SOURCES:.c=.o)

LIBFT		= libft/libft.a
INCLUDE		= ./include/

all : $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -I $(INCLUDE) -o $(NAME)

$(LIBFT):
	make -C libft

%.o:%.c
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

clean :
	$(RM) $(OBJECTS)
	make clean -C libft

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)


re : fclean all

.PHONY : all clean fclean re