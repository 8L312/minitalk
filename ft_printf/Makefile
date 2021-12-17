# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 15:29:04 by rmonney           #+#    #+#              #
#    Updated: 2021/11/10 16:46:33 by rmonney          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c utils1.c utils2.c

OBJS	= ${SRCS:.c=.o}

RM		= rm -f

NAME	= libftprintf.a

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

.c.o:
			${CC} ${FLAG} -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
