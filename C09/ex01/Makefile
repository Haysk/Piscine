# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/20 17:23:32 by adylewsk          #+#    #+#              #
#    Updated: 2019/07/21 16:10:22 by adylewsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
FLAGS=-Wall -Wextra -Werror
SRCS=srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS=${SRCS:.c=.o}

all : libft.a

libft.a : ${OBJS}
	ar rc libft.a ${OBJS}
	ranlib libft.a

.c.o : ${SRCS}
	${CC} ${FLAGS} -c -Iincludes/ $< -o ${<:.c=.o}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f libft.a

re : fclean
	make all

.PHONY : all clean fclean re
