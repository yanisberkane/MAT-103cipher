##
## EPITECH PROJECT, 2021
## BSQ
## File description:
## Makefile for BSQ
##

SRC	=	main.c	\
		operate_on_matrix.c	\
		uncrypt_matrix.c

CFLAGS	=	-Wall -Wextra -g3

LDFLAGS	=	-L. -lmy -lm

OBJ	=	$(SRC:.c=.o)

NAME	=	103cipher

all:	$(NAME)

$(NAME):	$(OBJ)
	make	-C	lib/my/
	gcc	-o	$(NAME)	$(SRC) -g $(LDFLAGS)

clean:
	rm -f	$(OBJ)
	rm -f *~
	rm -f '#'*'#'
	make	-C	lib/my/	clean

fclean:	clean
	rm	-f	$(NAME)
	make	-C	lib/my/	fclean

re:	fclean all

.PHONY = $(NAME) clean fclean re
