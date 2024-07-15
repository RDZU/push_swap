# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: razamora <razamora@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 20:02:51 by razamora          #+#    #+#              #
#    Updated: 2024/03/28 13:14:18 by razamora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
AR = ar -rcs
FRM = rm -rf
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c ft_memcpy.c ft_calloc.c ft_strdup.c ft_bzero.c \
ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_atoi.c ft_strlen.c \
ft_strjoin.c ft_itoa.c ft_striteri.c ft_strmapi.c ft_substr.c ft_strtrim.c ft_split.c \
ft_putstr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS = ft_lstsize_bonus.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c ft_lstdelone_bonus.c ft_lstadd_back_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${BONUS:.c=.o}

DEFAULT_PART = .default
BONUS_PART = .bonus

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(DEFAULT_PART)

all: $(DEFAULT_PART)

$(DEFAULT_PART):$(OBJS)
		 $(AR) $(NAME) $(OBJS)
		 @touch $(DEFAULT_PART)

$(BONUS_PART): $(OBJS_BONUS)
		$(AR) $(NAME) $(OBJS_BONUS)
		@touch $(BONUS_PART)

bonus: $(BONUS_PART)

clean:
	$(FRM) $(OBJS) $(OBJS_BONUS)
	$(FRM) $(DEFAULT_PART) $(BONUS_PART)

fclean: clean
	$(FRM) $(NAME)

re: fclean all

.PHONY: $(NAME) re fclean all clean bonus