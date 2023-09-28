# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbenoit <cbenoit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/26 14:29:30 by cbenoit           #+#    #+#              #
#    Updated: 2018/12/06 13:58:51 by cbenoit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	feel_it/main.c feel_it/error.c feel_it/solver.c feel_it/recur.c

LIBFT = libft/libft.a

SUPPR = main.o error.o solver.o recur.o

HEADER = ./fillit/fillit.h

all: $(NAME)

$(NAME):
	@make -C libft/
	gcc -c -Wall -Wextra -Werror $(SRC)
	gcc -o $(NAME) -Wall -Wextra -Werror $(SUPPR) $(LIBFT) -I $(HEADER)
	@mv $(SUPPR) feel_it/ 

clean:
	@make -C libft/ clean
	@rm -f feel_it/main.o feel_it/error.o feel_it/solver.o feel_it/recur.o

fclean: clean
	@make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
