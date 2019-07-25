CC=gcc
FLAGS=-Wall -Wextra -Werror
SRCS=do_op.c ft_atoi.c operations.c put.c
OBJS=${SRCS:.c=.o}
EXEC=do-op

${EXEC} : ${OBJS}
	${CC} ${FLAGS} -o $@ ${OBJS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm ${EXEC}

re : fclean
	make ${EXEC}

.PHONY : ${EXEC} clean fclean re