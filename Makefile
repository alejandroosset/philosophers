# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 12:10:36 by aosset-o          #+#    #+#              #
#    Updated: 2025/08/11 12:18:13 by aosset-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Werror -Wextra


NAME = philosophers
SRC = main.c 
OBJ = $(SRC:.c=.o)

INCLUDE = philosophers.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(NAME): $(GREEN)$(OBJ) was created$(RESET)"
clean:
	@rm -f $(OBJ)
	@echo "$(NAME): $(RED)$(OBJ) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"
fclean: clean
	@rm $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
re: fclean all

.PHONY: all clean fclean re