# PIPEX MAKEFILE #

# Output Colors
CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

# Global Config
NAME		= pipex
LIBFT_DIR	= ./libft
LIBFT		= libft.a
CC			= cc
SRCS		= src/main.c src/utils.c
HEADER		= src/pipex.h

OBJS			= $(SRCS:.c=.o)
CFLAGS			= -Wall -Wextra -Werror

all: compile_lib $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L. $(LIBFT_DIR)/$(LIBFT)
	@echo "$(GREEN)$(NAME) created ✓${CLR_RMV}"

compile_lib:
	cd $(LIBFT_DIR) && $(MAKE)

clean:
	rm -rf $(OBJS)
	cd $(LIBFT_DIR) && $(MAKE) clean

fclean: clean
	rm -rf $(LIBFT_DIR)/$(LIBFT)
	rm -rf $(NAME)

norme:
		@norminette $(SRCS) $(HEADERS) 

re: fclean all

.PHONY: all re clean fclean
