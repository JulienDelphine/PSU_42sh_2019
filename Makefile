##
## EPITECH PROJECT, 2020
## minishell2
## File description:
## Makefile
##

SRC	=	src/main_mysh.c	\
		src/handle_errors.c		\
		src/usefull/signal.c	\
		src/usefull/init.c		\
		src/usefull/free.c		\
		src/usefull/split_function.c	\
		src/usefull/count_words.c	\
		src/usefull/tools.c		\
		src/usefull/get_path.c	\
		src/builtin/my_exit.c	\
		src/builtin/antcd.c	\
		src/builtin/builtins.c	\
		src/builtin/my_cd.c	\
		src/redirect/redirection.c	\
		src/redirect/my_pipe.c	\
		src/redirect/double_left.c	\
		src/redirect/errorpipes.c	\
		src/env/setenv.c	\
		src/env/errsetenv.c	\
		src/env/strcmpforenv.c	\
		src/env/env.c	\
		src/exec/exec.c	\
		src/exec/seg_and_div.c	\
		src/my_echo/combine_str.c	\
		src/my_echo/my_echo.c	\
		src/my_echo/switch_echo.c	\
		src/exec/parsing.c

NAME	=	42sh

CFLAGS	=	-Wall -Wextra -g

IFLAGS	=	-I./include/

LIB		=	-L lib/my/ -l my

all:	$(NAME)

$(NAME):
	make -C  lib/my
	gcc -o $(NAME) $(CFLAGS) $(IFLAGS) $(SRC) $(LIB)

clean:
	make -C lib/my clean
	rm -f *.o
	rm -f *.~
	rm -f vgcore*

fclean:
	make -C lib/my fclean
	rm -f $(NAME)
	rm -f *.~
	rm -f vgcore*

re:	fclean all
