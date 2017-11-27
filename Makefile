# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/15 13:14:57 by cnovo-ri          #+#    #+#              #
#    Updated: 2017/10/25 05:59:54 by cnovo-ri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_select

SRC=build.c

LIB=./libft/libft.a

HEADER=-I./

OBJ=$(SRC:.c=.o)

FLAGS=-Wall -Wextra -Werror

CC=cc

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
#	@$(CC) $(FLAGS) -c $(SRC) -I . -I ./libft -L. -ltermcap
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(HEADER) $(LIB) -L. -ltermcap
	@echo "\033[1m\033[32m[ ✔ ]Compiled :\033[0m $(NAME) ࿇"

clean:
	@rm -f $(OBJ)
	@make clean -C ./libft
	@echo "\033[1m\033[32m[ ✔ ]Deleted :\033[0m $(OBJ) ࿇"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./libft
	@echo "\033[1m\033[32m[ ✔ ]Deleted :\033[0m $(NAME) ࿇"

re: fclean all

.PHONY: all clean fclean re
