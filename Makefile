# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fanno <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/29 11:05:21 by fanno             #+#    #+#              #
#    Updated: 2016/11/20 13:31:27 by fanno            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

PATH_SRC = source/

PATH_INC = include/

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = main.c\
	  fractal.c\
	  fractal2.c\
	  input.c\
	  help.c\
	  display.c\
	  parsing_arg.c\
	  tools.c\

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all:	$(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@printf "Compiling $(NAME) ...\n"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@printf "fractol compiled\n"

%.o: %.c
	@$(CC) $(FLAGS) $(HEADERS) -c -o $@ $^
	@printf "[\e[32mfractol object\e[0m]\e[32m--\e[0m--\e[32m--\e[0m> : $@"
	@printf "\e[0m\n"

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean

.PHONY: clean fclean all
