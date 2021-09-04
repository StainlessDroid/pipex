# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/24 18:37:12 by mpascual          #+#    #+#              #
#    Updated: 2021/09/05 01:48:19 by mpascual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# To include bonus in compilation call makefile with "WITH_BONUS=1" argument

NAME = pipex
REG_SRC_FILES = pipex.c
BONUS_SRC_FILES = bonus/*.o
HEADER = pipex.h
LIB_PATH = libft_printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
SRC = $(REG_SRC_FILES) $(BONUS_SRC_FILES)
else
SRC = $(REG_SRC_FILES)
endif

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L. $(LIB_PATH)

lib:
	cd libft_printf && make re && make clean && cd ../

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus:
	$(MAKE) WITH_BONUS=1 all

norme: clean
	@norminette $(SRC)

.PHONY: all clean fclean re
