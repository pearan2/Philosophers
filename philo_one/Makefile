# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honlee <honlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 05:28:05 by honlee            #+#    #+#              #
#    Updated: 2021/03/30 06:20:20 by honlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		\
					main.c\
					../share/ft_atoi.c\
					../share/ft_salloc.c\

OBJS        =       ${SRCS:.c=.o}

INCDIR		=		./share/

NAME		=		philo_one

CC			=		gcc

#CF			=		-Wall -Wextra -Werror
CF			=		-g
.c.o       	:
					${CC} ${CF} -c $< -o ${<:.c=.o} -I${INCDIR}

${NAME}     :       ${OBJS}
					${CC} ${CF} ${OBJS} -o ${NAME}

fclean		:		clean
					rm -f ${NAME}

clean       :               
					rm -f ${OBJS}

re			:		fclean all

all         :      	${NAME}