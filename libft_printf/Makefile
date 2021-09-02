# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/14 17:01:42 by mpascual          #+#    #+#              #
#    Updated: 2020/10/06 16:52:08 by mpascual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRC = src/ft_printf.c src/utils.c src/print_cs.c src/print_di.c \
		src/print_xp.c src/print_u.c

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	cd libft && make
	cp libft/libft.a $(NAME)
	ar -crs $(NAME) $(OBJS)

norme: fclean
	@norminette ./libft/
	@norminette ./src/
	@norminette ./header.h

all: $(NAME)

clean:
	rm -rf $(OBJS)
	cd libft && make fclean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean
