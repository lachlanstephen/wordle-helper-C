# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darkwater <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 19:03:04 by darkwater         #+#    #+#              #
#    Updated: 2023/06/15 19:11:30 by darkwater        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= wordle-solver

SRC				= main.c file_handling.c wordle_solver.c

SRCPRE			= ${addprefix ${PREFIX}, ${SRC}}

OBJS			= ${SRCPRE:.c=.o}

PREFIX			= ./src/

HEADER			= ./includes/

CC				= cc

CFLAGS			= -Wall -Werror -Wextra

all: ${NAME}

.c.o: .c
	${CC} ${CFLAGS} -c -I ${HEADER} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re 
