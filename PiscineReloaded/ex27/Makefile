CC=gcc -c

FLAG=-Wall -Werror -Wextra

GC=gcc

AR=ar rc

RM=rm -f

NAME=lib.a

SRCS=srcs/ft_putchar.c srcs/ft_putstr.c

OBJECTS=ft_putchar.o ft_putstr.o

PROJECT=ft_display_file.c

APP_NAME=ft_display_file

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
