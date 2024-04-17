##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	$(wildcard src/*.c)				\
		$(wildcard src/utils/*.c)		\
		$(wildcard src/commands/*.c)	\

TESTSRC	=	$(wildcard lib/*.c)				\
			src/str_to_arrayv2.c			\
			$(wildcard tests/put/*.c)		\
			$(wildcard tests/str/*.c)		\
			$(wildcard tests/lib/*.c)		\

LIBNAME	=	libmy.a

SRCLIB	=	$(wildcard lib/*.c)

OBJLIB	=	$(SRCLIB:.c=.o)

OBJ	=	$(SRC:.c=.o)

CFLAGS  =	-Wall -Wextra -I ./include/ -lncurses

LDFLAGS		=	-L. -lmy

HEADER	=	my.h

NAME	=	42sh

TEST	=	uni_tests

all:	$(NAME)

create_lib:	$(OBJLIB)
	ar rc $(LIBNAME) $(OBJLIB)

$(NAME):	create_lib	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(OBJLIB)
	rm -f $(NAME)
	rm -f $(TEST)
	rm -f $(LIBNAME)

fclean:	clean
	rm -f *~
	rm -f *.gc*
	rm -f *vgcore*
	rm -f *.log
	rm -f *.gcno
	rm -f *.gcda

re:	fclean all

$(TEST):	fclean
	$(CC) -o $(TEST) $(TESTSRC) --coverage -lcriterion $(CFLAGS)

tests_run:	$(TEST)
	./$(TEST)
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

.PHONY:	all clean fclean re $(TEST) tests_run
