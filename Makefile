NAME = libftprintf.a

SRC = ft_printf.c\
	  ft_itoa.c\
	  ft_utils_1.c\
	  ft_utils_2.c
	  
#SRCS_BONUS = ft_lstnew.c\
			 
OBJS = $(SRC:.c=.o)

#OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = gcc -Wall -Werror -Wextra

LIBC = ar rcs

RM = rm -f

%.o: %.c
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $@ $^

#bonus: $(OBJS_BONUS)
#	$(LIBC) $(NAME) $^

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean bonus fclean re
