# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 20:46:54 by mpascual          #+#    #+#              #
#    Updated: 2020/11/17 20:34:31 by mpascual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c \
	  ft_calloc.c ft_memccpy.c ft_memchr.c ft_memcpy.c ft_memcmp.c\
	  ft_memmove.c ft_memset.c ft_putchar_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c\
	  ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	  ft_strmapi.c ft_strncmp.c\
	  ft_strnstr.c ft_strrchr.c \
	  ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	  ft_putchar.c ft_putstr.c \
	  ft_itoa.c ft_nbrlen.c get_next_line.c


BONUS = $(SRC) *_bonus.c

OBJ = $(subst .c,.o,$(SRC))
BONUS_OBJ = $(subst .c,.o,$(BONUS))

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

OBJ : $(subst .o,.c,$(SRC))
	gcc -c $(CFLAGS) $(SRC)

bonus :
	    gcc $(CFLAGS) -c $(BONUS)
	    ar rc $(NAME) $(BONUS_OBJ)
	    ranlib $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)


clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

main : main.c libft.a
	gcc -Wall -Wextra -Werror main.c libft.a

.PHONY: clean fclean all re
