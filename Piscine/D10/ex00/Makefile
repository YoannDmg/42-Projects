# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydemange <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/15 17:08:58 by ydemange          #+#    #+#              #
#    Updated: 2018/08/20 11:32:23 by ydemange         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc -c

AR=ar rc

RM=rm -f

NAME=libft.a

SRCS=srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c\
	 srcs/ft_strlen.c srcs/ft_swap.c

OBJECTS=ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

HEADERS_FOLDER=includes/

all:$(NAME)

$(NAME):
	$(CC) $(SRCS)
	$(AR) $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean:clean
	$(RM) $(NAME)

re:fclean all
