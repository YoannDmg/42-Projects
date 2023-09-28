CC=cc
FLAG=-Wall -Wextra -Werror
LIB_DIR=./libft
LIB=./libft/libft.a
EXEC=fdf
SRC=src/main.c\
	src/parser.c\
	src/fdf.c \
	src/event.c \
	src/draw.c \
	src/event_move.c

all:$(EXEC)

$(EXEC) :$(SRC)
		@(cd $(LIB_DIR) && $(MAKE))
		$(CC) $(FLAG) -I /usr/local/include  $(SRC) $(LIB) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(EXEC)

clean:
	@(cd $(LIB_DIR) && $(MAKE) $@)

fclean: clean
		@(cd $(LIB_DIR) && $(MAKE) $@)
		rm -rf $(EXEC)

re: fclean all

.PHONY : all, clean, fclean, re
