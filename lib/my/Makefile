##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	my_printf.c	\
		my_putstr.c	\
		my_put_nbr.c	\
		my_octo_base.c	\
		my_putchar.c	\
		my_hexa_base.c	\
		my_revstr.c	\
		my_strvalist.c	\
		my_charvalist.c	\
		my_maj_hexa.c	\
		my_binary_base.c	\
		my_u_nbr.c	\
		handle_errors.c		\
		my_strstr.c			\
		my_str_to_word_array.c	\
		my_get_nbr.c	\
		my_strlen.c		\
		my_strcat.c		\
		my_strcmp.c		\
		clean_str.c		\
		my_str_isnum.c	\
		my_strcut.c		\
		my_strdup.c		\
		my_strncmp.c

CFLAGS		=	-Wall -Wextra -I../../include/

OBJ		=	$(SRC:.c=.o)

HEAD    =   my.h

NAME	=	libmy.a

all: 	$(NAME)

$(NAME):		$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
