# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 12:16:19 by pojea-lo          #+#    #+#              #
#    Updated: 2022/01/14 12:16:26 by pojea-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c\
	  ft_itoa.c\
	  ft_utils_1.c\
	  ft_utils_2.c\
	  ft_utils_3.c
			 
OBJS = $(SRC:.c=.o)

CC = gcc -Wall -Werror -Wextra

LIBC = ar rcs

RM = rm -f

%.o: %.c
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean bonus fclean re
