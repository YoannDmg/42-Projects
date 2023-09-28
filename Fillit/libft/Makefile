# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbenoit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/26 14:29:30 by cbenoit           #+#    #+#              #
#    Updated: 2018/11/18 15:28:33 by cbenoit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c
SRC +=	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c
SRC +=	ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c
SRC +=	ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c
SRC +=	ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c
SRC +=	ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c
SRC +=	ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c
SRC +=	ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c
SRC +=	ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c
SRC +=	ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c
SRC +=	ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c
SRC +=	ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c
SRC +=	ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c
SRC +=	ft_toupper.c ft_lstnew.c ft_is_prime.c
SRC +=	ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c
SRC +=	ft_lstmap.c ft_create_elem.c ft_list_push_back.c
SRC +=	ft_list_push_front.c ft_list_size.c *ft_list_last.c
SRC +=	*ft_list_push_params.c ft_list_clear.c
SRC +=	ft_count_if.c ft_is_sort.c
SRC +=	ft_any.c *ft_map.c ft_foreach.c
SRC +=	ft_swap.c ft_div_mod.c ft_ultimate_div_mod.c
SRC +=	ft_sort_integer_table.c ft_iterative_factorial.c ft_recursive_factorial.c
SRC +=  ft_iterative_power.c ft_recursive_power.c ft_sqrt.c

SUPPR = $(SRC:.c=.o)

HEADER = ./libft.h

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC) -I $(HEADER)
	ar rv $(NAME) $(SUPPR)

clean:
	/bin/rm -f $(SUPPR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
