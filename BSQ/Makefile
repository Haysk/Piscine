CC=gcc
FLAGS=-Wall -Wextra -Werror
SRCS=${MAIN} $(wildcard tools/*.c) ${wildcard file/*.c} ${wildcard solver/*.c}
MAIN=main.c
OBJS=${SRCS:.c=.o}
EXEC=bsq

all: ${EXEC}

${EXEC} : ${OBJS}
	${CC} ${FLAGS} -Iheader/ -o $@ ${OBJS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm ${EXEC}

re : fclean
	make ${EXEC}

.PHONY : ${EXEC} clean fclean re