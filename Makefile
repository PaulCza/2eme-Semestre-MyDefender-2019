##
## EPITECH PROJECT, 2019
## makefile
## File description:
## compile everything
##

SRC	=	display_window.c	\
		my_itoa.c		\
		end_screen.c	\
		play.c			\
		main_menu.c		\
		main.c	\
		enemy1.c			\
		enemy2.c	\
		initialize.c \
		initialize2.c	\
		initialize3.c	\
		play2.c	\
		choice.c		\
		pause_menu.c	\

OBJ	=       $(SRC:.c=.o)

NAME	=	my_defender

CPPFLAG	= 	-Wall -Wextra -Iinclude

all:	$(NAME) clean

$(NAME):        $(OBJ)
	gcc $(SRC) -o $(NAME) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio $(CPPFLAG)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:     fclean all
