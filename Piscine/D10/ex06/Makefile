# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydemange <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 10:48:14 by ydemange          #+#    #+#              #
#    Updated: 2018/08/20 23:02:14 by ydemange         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc -c

FLAG=-Wall -Werror -Wextra

GC=gcc 

AR=ar rc

RM=rm -f

NAME=lib.a

SRCS=srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_atoi.c srcs/ft_putnbr.c 

OBJECTS=ft_putchar.o ft_putstr.o ft_atoi.o ft_putnbr.o

PROJECT=project/do_op.c project/operation.c

APP_NAME=do-op

all:$(NAME)

$(NAME):
	$(CC) $(SRCS)
	$(AR) $(NAME) $(OBJECTS)
	$(GC) $(FLAG) $(PROJECT) $(NAME) -o $(APP_NAME)

clean:
	$(RM) $(OBJECTS)

fclean:clean
	$(RM) $(NAME) $(APP_NAME)

re:fclean all
