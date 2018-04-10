##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makes
##

SRC	=	src/main.c	\
		src/my_putstr.c	\
		src/init.c	\
		src/move.c	\
		src/handling.c	\
		src/check.c	\
		src/init_bis.c	\
		src/map.c	\
		src/my_putchar.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

CFLAGS  =	-W -Wall -Wextra -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lc_graph_prog

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

my:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-audio -lcsfml-system
