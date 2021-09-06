# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/24 18:37:12 by mpascual          #+#    #+#              #
#    Updated: 2021/09/06 10:31:54 by mpascual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# To include bonus in compilation call makefile with "WITH_BONUS=1" argument

NAME = pipex
REG_SRC_FILES = src/pipex.c src/utils.c src/ft_split.c src/ft_strjoin.c \
				src/ft_strnstr.c src/ft_strlen.c
BONUS_SRC_FILES = bonus/*.o
HEADER = pipex.h
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
SRC = $(REG_SRC_FILES) $(BONUS_SRC_FILES)
else
SRC = $(REG_SRC_FILES)
endif

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

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
