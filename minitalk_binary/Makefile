# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 15:17:04 by rmonney           #+#    #+#              #
#    Updated: 2021/12/16 23:37:18 by rmonney          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main_server.c

SRCS2	= main_client.c ft_atoi.c

OBJS	= ${SRCS:.c=.o}

OBJS2	= ${SRCS2:.c=.o}

RM		= rm -f

NAME	= server

NAME2	= client

FLAGS	= -Wall -Werror -Wextra

CC		= gcc

PRINTF	= ./ft_printf/

IPRINTF	= -I ${PRINTF}

LPRINTF = -L ${PRINTF} -lftprintf

all:		${NAME} ${NAME2}

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C ${PRINTF}
			${CC} ${FLAGS} ${IPRINTF} -o ${NAME} ${OBJS} ${LPRINTF}

${NAME2}:	${OBJS2}
			make -C ${PRINTF}
			${CC} ${FLAGS} ${IPRINTF} -o ${NAME2} ${OBJS2} ${LPRINTF}

clean:
			${RM} ${OBJS}
			${RM} ${OBJS2}

fclean:		clean
			${RM} ${NAME}
			${RM} ${NAME2}

re:			fclean all

.PHONY:		all clean fclean re
